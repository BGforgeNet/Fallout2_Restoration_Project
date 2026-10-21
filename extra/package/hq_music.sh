#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
sound_dir="$release_dir/data/sound/music"

rm -rf "$sound_dir"
mkdir -p "$sound_dir"
cd "$sound_dir"
# shellcheck disable=SC2154  # from env.sh
url="$("$extra_dir"/package/release_url.sh "$hq_music_repo" 'fallout_music_hq_.*\.zip')"
wget -nv "$url"
unzip fallout_music_hq*.zip
rm -f fallout_music_hq*.zip
