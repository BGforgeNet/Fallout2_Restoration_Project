#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
# The release also ships hero_appearance_non_canon_*.zip, which this pattern leaves out.
# shellcheck disable=SC2154  # from env.sh
url="$("$extra_dir"/package/release_url.sh "$appearance_repo" 'hero_appearance_v.*\.zip')"
wget -nv "$url"
unzip hero_appearance*.zip
rm -f hero_appearance*.zip
