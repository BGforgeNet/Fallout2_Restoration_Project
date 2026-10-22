#!/bin/bash

set -xeu -o pipefail

cd "$RELEASE_DIR"
for f in cassidy_head cassidy_voice_joey_bracken_hq; do
  url="$("$EXTRA_DIR"/package/release_url.sh "$CASSIDY_HEAD_REPO" "$f\.dat")"
  wget -nv "$url"
  mv "$f.dat" mods/
done
