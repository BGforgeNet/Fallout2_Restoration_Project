#!/bin/bash

set -xeu -o pipefail

export comp_dir="components"
# shellcheck disable=SC2154  #  bin_dir from env.sh
export dat2="wine $bin_dir/dat2.exe"
export dat2a="wine $bin_dir/dat2.exe a"
trans_dir="$(realpath translations)"
export trans_dir
file_list="$(realpath dat2.list)"
export file_list

short_sha="$(git rev-parse --short HEAD)"
# defaults, local build or github non-tagged
export version="2.4.git$short_sha"
export vversion="$version" # in package names

if [[ -n "${GITHUB_REF-}" ]]; then                 # github build
    if echo "$GITHUB_REF" | grep "refs/tags"; then # tagged
        # shellcheck disable=SC2001  #  sed is more readable
        version="$(echo "$GITHUB_REF" | sed 's|refs\/tags\/v||')"
        export version
        export vversion="v$version"
    fi
fi

# cleanup for local build
git checkout -- release
git clean -fd release
git clean -fdX release

# wine pollutes the log with "wine: Read access denied for device" if z is linked to /
z="$(readlink -f ~/.wine/dosdevices/z:)"
if [[ "$z" == "/" ]]; then
    rm -f ~/.wine/dosdevices/z:
    ln -s /home ~/.wine/dosdevices/z:
fi

# translations packaged first, to get extra text out of the way
# shellcheck disable=SC2154  # extra_dir from env.sh
"$extra_dir"/package/translations.sh

# data
# shellcheck disable=SC2154  # from env.sh
dat="$mod_name.dat"
# shellcheck disable=SC2154  # from env.sh
mkdir -p "$mods_dir"

cd data
# I don't know how to pack recursively
find . -path ./sound/music -prune -o -type f -print | sed -e 's|^\.\/||' -e 's|\/|\\|g' | sort >"$file_list" # replace slashes with backslashes
$dat2a "$mods_dir/$dat" @"$file_list"
cd ..

# pack components into separate dat files
"$extra_dir"/package/components.sh

# pack appearance, too
"$extra_dir"/package/appearance.sh

# cassidy head and voice
"$extra_dir"/package/cassidy_head.sh

# party orders
"$extra_dir"/package/party_orders.sh

# hq music
"$extra_dir"/package/hq_music.sh

# sfall
"$extra_dir"/package/sfall.sh

# npc armor mod from sfall
"$extra_dir"/package/npc_armor.sh

# ammo mod from sfall
"$extra_dir"/package/ammo.sh

# hi-res patch files
"$extra_dir"/package/f2_res.sh

# manual package: linux/mac os
pushd .
# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
zip -r "${mod_name}_${vversion}.zip" -- * # our package
popd
mv "$release_dir/${mod_name}_${vversion}.zip" .

# exe installer
"$extra_dir"/package/inno.sh

# cleanup for local build
git checkout -- data/text release extra/inno/inno.iss
git clean -fd translations
git clean -fdX translations
