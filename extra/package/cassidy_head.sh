#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
for f in cassidy_head cassidy_voice_joey_bracken_hq; do
  # shellcheck disable=SC2154  # from env.sh
  url="$("$extra_dir"/package/release_url.sh "$cassidy_head_repo" "$f\.dat")"
  wget -nv "$url"
  mv "$f.dat" mods/
done
