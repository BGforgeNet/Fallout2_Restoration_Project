#!/bin/bash

set -xeu -o pipefail

sound_dir="$RELEASE_DIR/data/sound/music"

rm -rf "$sound_dir"
mkdir -p "$sound_dir"
cd "$sound_dir"
url="$("$EXTRA_DIR"/package/release_url.sh "$HQ_MUSIC_REPO" 'fallout_music_hq_.*\.zip')"
wget -nv "$url"
unzip fallout_music_hq*.zip
rm -f fallout_music_hq*.zip
