#!/bin/bash

set -xeu -o pipefail

COMP_DIR="components"

# pack components into separate dat files
if [[ -d "$COMP_DIR" ]]; then
    cd "$COMP_DIR"
    # shellcheck disable=SC2045  # let it break on strange names
    for c in $(ls); do
        DAT_FILE="${MOD_NAME}_$c.dat"
        "$DAT3" a -c "$DAT3_LEVEL" -C "$c" "$MODS_DIR/$DAT_FILE" '*'
    done
    cd ..
fi
