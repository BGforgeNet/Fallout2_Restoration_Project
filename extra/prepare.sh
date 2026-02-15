#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
mpack_file="modderspack_$mpack_version.7z"
mpack_url="https://sourceforge.net/projects/sfall/files/Modders%20pack/$mpack_file/download"
sfall_headers_dir="scripts_src/sfall"

# Download sslc compiler
if [[ ! -f "$COMPILE" ]]; then
    wget -q "$SSLC_URL" -O "$COMPILE"
    chmod +x "$COMPILE"
fi

# shellcheck disable=SC2154  # from env.sh
wget -nv "$mpack_url" -O "$mpack_7z"
# sfall headers
rm -rf "$sfall_headers_dir" "scripting_docs/headers"
7zr x "$mpack_7z" "scripting_docs/headers"
mv "scripting_docs/headers" "$sfall_headers_dir"
