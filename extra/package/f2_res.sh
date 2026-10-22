#!/bin/bash

set -xeu -o pipefail

cd "$RELEASE_DIR"
url="$("$EXTRA_DIR"/package/release_url.sh BGforgeNet/f2_res 'f2_res_.*\.zip')"
wget -nv "$url"
unzip f2_res*.zip
mv f2_res.dat mods/
rm -f f2_res*.zip
