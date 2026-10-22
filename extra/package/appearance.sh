#!/bin/bash

set -xeu -o pipefail

cd "$RELEASE_DIR"
# The release also ships hero_appearance_non_canon_*.zip, which this pattern leaves out.
url="$("$EXTRA_DIR"/package/release_url.sh "$APPEARANCE_REPO" 'hero_appearance_v.*\.zip')"
wget -nv "$url"
unzip hero_appearance*.zip
rm -f hero_appearance*.zip
