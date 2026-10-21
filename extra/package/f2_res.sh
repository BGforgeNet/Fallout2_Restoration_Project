#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
# shellcheck disable=SC2154  # from env.sh
url="$("$extra_dir"/package/release_url.sh BGforgeNet/f2_res 'f2_res_.*\.zip')"
wget -nv "$url"
unzip f2_res*.zip
mv f2_res.dat mods/
rm -f f2_res*.zip
