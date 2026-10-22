#!/bin/bash

set -xeu -o pipefail

mpack_file="modderspack_$MPACK_VERSION.7z"
mpack_url="https://sourceforge.net/projects/sfall/files/Modders%20pack/$mpack_file/download"
sfall_headers_dir="scripts_src/sfall"

# Download sslc compiler
if [[ ! -f "$COMPILE" ]]; then
    wget -q "$SSLC_URL" -O "$COMPILE"
    chmod +x "$COMPILE"
fi

# Download dat3 tool if it doesn't exist
if [[ ! -f "$DAT3" ]]; then
    # shellcheck disable=2154
    wget -q "$DAT3_URL" -O "$DAT3"
    chmod +x "$DAT3"
fi

if [[ ! -f "$MPACK_7Z" ]]; then
    mkdir -p "$DOWNLOADS_DIR"
    # Through a temporary name, so an interrupted download is never taken for a complete one.
    wget -nv "$mpack_url" -O "$MPACK_7Z.part"
    mv "$MPACK_7Z.part" "$MPACK_7Z"
fi
# sfall headers
rm -rf "$sfall_headers_dir" "scripting_docs/headers"
7zr x "$MPACK_7Z" "scripting_docs/headers"
mv "scripting_docs/headers" "$sfall_headers_dir"
