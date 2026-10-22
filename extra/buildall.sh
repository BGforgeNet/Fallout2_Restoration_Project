#!/bin/bash

set -xeu -o pipefail

# exporting for subshell
SRC="$(realpath scripts_src)"
export SRC
DST="$(realpath data/scripts)"
export DST
SCRIPTS_LST="$DST/scripts.lst"
export SCRIPTS_LST

# Preprocess and compile one script. Scripts are independent, so they build in parallel below.
compile() {
	local f int
	cd "$(dirname "$1")"
	f="$(basename "$1")"
	# shellcheck disable=SC2001  # Simple replacement doesn't work, need regex.
	int="$(echo "$f" | sed 's|\.ssl$|.int|')"
	gcc -E -x c -P -Werror -Wfatal-errors -o "${f}.tmp" "$f"
	"$COMPILE" -l -O2 -s -q -n "${f}.tmp" -o "$DST/$int"
}
export -f compile

# One pass selects the scripts: a process per script (grep over scripts.lst) would starve the compile jobs.
# shellcheck disable=SC2016  # $1 expands in the child shell.
printf '%s\n' "$SRC"/*/* | awk -v lst="$SCRIPTS_LST" -f "$(dirname "$0")/select_scripts.awk" |
	xargs -P "$(getconf _NPROCESSORS_ONLN)" -I{} bash -xeuc 'compile "$1"' _ {}
