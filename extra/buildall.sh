#!/bin/bash

set -xeu -o pipefail

# exporting for subshell
src="$(realpath scripts_src)"
export src
dst="$(realpath data/scripts)"
export dst
scripts_lst="$dst/scripts.lst"
export scripts_lst

# compile all
# shellcheck disable=SC2045  # We shouldn't have non-alphanumeric names here.
for d in $(ls "$src"); do
	if [[ -d "$src/$d" && "$d" != "template" ]]; then # if it's a dir and not a template
		cd "$src/$d"
		# build file list
		# shellcheck disable=SC2010  # We shouldn't have non-alphanumeric names here.
		for f in $(ls | grep -i "\.ssl$"); do
			# shellcheck disable=SC2001  # Simple replacement doesn't work, need regex.
			int="$(echo "$f" | sed 's|\.ssl$|.int|')"
			if grep -qi "^$int " "$scripts_lst" || [[ "$d" == "global" ]]; then # if file is in scripts.lst or a global script
				# Preprocess
				gcc -E -x c -P -Werror -Wfatal-errors -o "${f}.tmp" "$f"
				# Compile
				"$COMPILE" -l -O2 -s -q -n "${f}.tmp" -o "$dst/$int"
			fi
		done
		cd ..
	fi
done
