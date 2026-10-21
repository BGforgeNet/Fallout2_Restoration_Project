#!/bin/bash

set -xeu -o pipefail

export optional_dir="optional"
mkdir -p "$optional_dir"
cd "$optional_dir"
for f in goris_fast_derobing_low_fps walk_speed_fix_low_fps; do
    # shellcheck disable=SC2154  # from env.sh
    url="$("$extra_dir"/package/release_url.sh BGforgeNet/fo2-alternative-animations "$f\.dat")"
    wget -nv "$url"
done
