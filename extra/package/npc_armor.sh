#!/bin/bash

set -xeu -o pipefail

cd "$RELEASE_DIR"
url="$("$EXTRA_DIR"/package/release_url.sh "$NPC_ARMOR_REPO" 'npc_armor_.*\.zip')"
wget -nv "$url"
unzip npc_armor*.zip "mods/*"
rm -f npc_armor*.zip
