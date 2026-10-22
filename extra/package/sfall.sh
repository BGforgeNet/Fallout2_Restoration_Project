#!/bin/bash

set -xeu -o pipefail

release_ini="$RELEASE_DIR/ddraw.ini"
custom_ini="$EXTRA_DIR/package/ddraw.ini"
sfall_url="https://sourceforge.net/projects/sfall/files/sfall/sfall_$SFALL_VERSION.7z/download"

if [[ ! -f "$SFALL_7Z" ]]; then
    mkdir -p "$DOWNLOADS_DIR"
    # Through a temporary name, so an interrupted download is never taken for a complete one.
    wget -nv "$sfall_url" -O "$SFALL_7Z.part"
    mv "$SFALL_7Z.part" "$SFALL_7Z"
fi

cd "$RELEASE_DIR"
files="
ddraw.dll
ddraw.ini
sfall.dat
sfall-FAQ.txt
sfall-readme.txt
mods/sfall-mods.ini
translations
"
for f in $files; do
    rm -rf "$f"
    7zr x "$SFALL_7Z" "$f"
done

# uncomment ini settings to preserve options' placement in ddraw.ini
entries="$(grep '=' "$custom_ini" | awk -F '=' '{print $1}')"
for e in $entries; do
    sed -i "s|^;$e=|$e=|" "$release_ini"
done

# then merge custom settings
crudini --merge "$release_ini" <"$custom_ini"
# set version string
sed -i "s|^;VersionString=|VersionString=|" "$release_ini"
crudini --set "$release_ini" "Misc" "VersionString" "FALLOUT II 1.02d  RPU ${VERSION}"
# crudini adds spaces arouns the values, need to remove them
sed -i "s|^\([[:alnum:]]\+\) = |\1=|" "$release_ini"
# for windows users
unix2dos "$release_ini"
