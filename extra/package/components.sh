#!/bin/bash

set -xeu -o pipefail

comp_dir="components"

# pack components into separate dat files
if [[ -d "$comp_dir" ]]; then
    cd "$comp_dir"
    # shellcheck disable=SC2045  # let it break on strange names
    for c in $(ls); do
        # shellcheck disable=SC2154  # from env.sh
        DAT_FILE="${mod_name}_$c.dat"
        # shellcheck disable=SC2154  # from env.sh
        "$DAT3" a -c 9 -C "$c" "$mods_dir/$DAT_FILE" '*'
    done
    cd ..
fi
