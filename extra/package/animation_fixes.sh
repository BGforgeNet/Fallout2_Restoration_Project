#!/bin/bash

set -xeu -o pipefail

export OPTIONAL_DIR="optional"
mkdir -p "$OPTIONAL_DIR"
cd "$OPTIONAL_DIR"
for f in goris_fast_derobing_low_fps walk_speed_fix_low_fps; do
    url="$("$EXTRA_DIR"/package/release_url.sh BGforgeNet/fo2-alternative-animations "$f\.dat")"
    wget -nv "$url"
done
