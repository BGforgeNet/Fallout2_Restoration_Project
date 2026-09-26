#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
sound_dir="$release_dir/data/sound/music"

rm -rf "$sound_dir"
mkdir -p "$sound_dir"
cp "$(realpath data/sound/music)"/*.acm "$sound_dir"
