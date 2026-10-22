#!/bin/bash

set -xeu -o pipefail

EXTRA_DIR="$(realpath extra)"
export EXTRA_DIR
export BIN_DIR="$EXTRA_DIR/bin"
RELEASE_DIR="$(realpath release)"
export RELEASE_DIR
export MODS_DIR="$RELEASE_DIR/mods"
export MPACK_VERSION=${MPACK_VERSION:-4.5.1}
export SFALL_VERSION=${SFALL_VERSION:-4.5.1}
# Release archives, fetched only when missing; CI caches this directory.
export DOWNLOADS_DIR="$EXTRA_DIR/downloads"
export MPACK_7Z="$DOWNLOADS_DIR/modderspack_$MPACK_VERSION.7z"
export SFALL_7Z="$DOWNLOADS_DIR/sfall_$SFALL_VERSION.7z"
export MOD_NAME=rpu
TRANS_DIR="$(realpath translations)"
export TRANS_DIR

export APPEARANCE_REPO="BGforgeNet/Fallout2_Hero_Appearance"
export CASSIDY_HEAD_REPO="BGforgeNet/Fallout2_Cassidy_Head"
export PARTY_ORDERS_REPO="BGforgeNet/Fallout2_Party_Orders"
export HQ_MUSIC_REPO="BGforgeNet/Fallout2-HQ-music"
export NPC_ARMOR_REPO="BGforgeNet/Fallout2_NPC_Armor"

SSLC_VERSION="2026-09-17-13-26-18"
export SSLC_URL="https://github.com/sfall-team/sslc/releases/download/${SSLC_VERSION}/sslc-linux"
export COMPILE="$BIN_DIR/sslc"

DAT3_VERSION="v0.11.0"
export DAT3_URL="https://github.com/BGforgeNet/dat3/releases/download/${DAT3_VERSION}/dat3"
export DAT3="$BIN_DIR/dat3"
# zlib level for every .dat: 6 packs in under half the time of 9, for archives about 1% larger.
export DAT3_LEVEL=6

# Inno Setup 6.7.1, pinned by digest: the tag moves.
export INNO_IMAGE="docker.io/amake/innosetup@sha256:e003376ba818547275fe10c95e2a29be0f2d12d45e9eb8f205b6672dc5685bb1"
