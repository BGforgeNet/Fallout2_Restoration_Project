#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
# shellcheck disable=SC2154  # from env.sh
wget -nv "$(curl -s "https://api.github.com/repos/BGforgeNet/f2_res/releases/latest" | grep browser_download_url | awk -F '"' '{print $4}')"
unzip f2_res*.zip
mv f2_res.dat mods/
rm -f f2_res*.zip
