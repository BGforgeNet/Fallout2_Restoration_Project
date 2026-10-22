#!/bin/bash

set -xeu -o pipefail

lang_dir="data/text"
TRANS_DIR="translations"
russian_sound_url="$("$EXTRA_DIR"/package/release_url.sh BGforgeNet/Fallout2_Sound 'upu_russian_sound\.dat')"

# delete unnecessary files
rm -rf "$lang_dir"/{po,readme.md,translation.patch}
rm -f "$lang_dir/english/cuts/intro.sve"

# update patchinf
# shellcheck disable=SC2045  # Let it break if there are weird filenames.
for lang in $(ls $lang_dir); do
    patchinf="$lang_dir/$lang/dialog/patchinf.msg"
    # display current version
    sed -i "s|2\.x\.x.|${VERSION}.|" "$patchinf"
done

# duplicate cuts for english language, otherwise sfall won't display them in english
cp -r "$lang_dir"/english/cuts{,_female}

# move texts to translation package dir
# shellcheck disable=SC2010  # shouldn't have non-alphanumeric filenames here
for d in $(ls $lang_dir | grep -v english); do
    rm -rf "$TRANS_DIR/$d/text"
    mkdir -p "$TRANS_DIR/$d/text"
    mv "$lang_dir/$d" "$TRANS_DIR/$d/text/"
done

# package into dats
cd "$TRANS_DIR"
rm -f ./*.dat
for d in *; do
    DAT_FILE="${MOD_NAME}_$d.dat"
    $DAT3 a -c "$DAT3_LEVEL" -C "$d" "$DAT_FILE" '*'
done
cd ..

pushd .
cd "$TRANS_DIR"
# russian sound packaged separately
wget "$russian_sound_url"
# .dat files are already compressed: stored, not deflated again.
zip -r -0 "${MOD_NAME}_${VVERSION}_translations.zip" -- *.dat # all translations, just text and graphics
popd
mv "$TRANS_DIR/${MOD_NAME}_${VVERSION}_translations.zip" .
