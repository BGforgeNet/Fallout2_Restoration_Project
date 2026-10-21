#!/bin/bash

set -xeu -o pipefail

lang_dir="data/text"
trans_dir="translations"
# shellcheck disable=SC2154  # from env.sh
russian_sound_url="$("$extra_dir"/package/release_url.sh BGforgeNet/Fallout2_Sound 'upu_russian_sound\.dat')"

# delete unnecessary files
rm -rf "$lang_dir"/{po,readme.md,translation.patch}
rm -f "$lang_dir/english/cuts/intro.sve"

# update patchinf
# shellcheck disable=SC2045  # Let it break if there are weird filenames.
for lang in $(ls $lang_dir); do
    patchinf="$lang_dir/$lang/dialog/patchinf.msg"
    # display current version
    # shellcheck disable=SC2154  # from package.sh
    sed -i "s|2\.x\.x.|${version}.|" "$patchinf"
done

# duplicate cuts for english language, otherwise sfall won't display them in english
cp -r "$lang_dir"/english/cuts{,_female}

# move texts to translation package dir
# shellcheck disable=SC2010  # shouldn't have non-alphanumeric filenames here
for d in $(ls $lang_dir | grep -v english); do
    rm -rf "$trans_dir/$d/text"
    mkdir -p "$trans_dir/$d/text"
    mv "$lang_dir/$d" "$trans_dir/$d/text/"
done

# package into dats
cd "$trans_dir"
rm -f ./*.dat
for d in *; do
    # shellcheck disable=SC2154  # from env.sh
    DAT_FILE="${mod_name}_$d.dat"
    $DAT3 a -c 9 -C "$d" "$DAT_FILE" '*'
done
cd ..

pushd .
cd "$trans_dir"
# russian sound packaged separately
wget "$russian_sound_url"
# shellcheck disable=SC2154  # from package.sh
zip -r "${mod_name}_${vversion}_translations.zip" -- *.dat # all translations, just text and graphics
popd
mv "$trans_dir/${mod_name}_${vversion}_translations.zip" .
