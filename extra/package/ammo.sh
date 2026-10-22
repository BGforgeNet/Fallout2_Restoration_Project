#!/bin/bash

set -xeu -o pipefail

scripts_dir="$RELEASE_DIR/data/scripts"

mkdir -p "$scripts_dir"
7zr e "$MPACK_7Z" example_mods/AmmoMod/gl_ammomod.int
mv gl_ammomod.int "$RELEASE_DIR/"

7zr e "$MPACK_7Z" example_mods/AmmoMod/AmmoGlovz.ini
7zr e "$MPACK_7Z" example_mods/AmmoMod/AmmoYAAM.ini
mv AmmoGlovz.ini "$RELEASE_DIR/mods/"
mv AmmoYAAM.ini "$RELEASE_DIR/mods/"
