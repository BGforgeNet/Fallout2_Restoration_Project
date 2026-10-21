#!/bin/bash

set -xeu -o pipefail

extra_dir="$(realpath extra)"
export extra_dir
export bin_dir="$extra_dir/bin"
release_dir="$(realpath release)"
export release_dir
export mods_dir="$release_dir/mods"
export mpack_version=${mpack_version:-4.5.1}
export mpack_7z="mpack.7z"
export sfall_version=${sfall_version:-4.5.1}
export mod_name=rpu
trans_dir="$(realpath translations)"
export trans_dir

export appearance_repo="BGforgeNet/Fallout2_Hero_Appearance"
export cassidy_head_repo="BGforgeNet/Fallout2_Cassidy_Head"
export party_orders_repo="BGforgeNet/Fallout2_Party_Orders"
export hq_music_repo="BGforgeNet/Fallout2-HQ-music"
export npc_armor_repo="BGforgeNet/Fallout2_NPC_Armor"

SSLC_VERSION="2026-09-17-13-26-18"
export SSLC_URL="https://github.com/sfall-team/sslc/releases/download/${SSLC_VERSION}/sslc-linux"
export COMPILE="$bin_dir/sslc"

DAT3_VERSION="v0.11.0"
export DAT3_URL="https://github.com/BGforgeNet/dat3/releases/download/${DAT3_VERSION}/dat3"
export DAT3="$bin_dir/dat3"
