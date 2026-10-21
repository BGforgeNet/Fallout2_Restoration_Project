#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
# shellcheck disable=SC2154  # from env.sh
url="$("$extra_dir"/package/release_url.sh "$npc_armor_repo" 'npc_armor_.*\.zip')"
wget -nv "$url"
unzip npc_armor*.zip "mods/*"
rm -f npc_armor*.zip
