#!/bin/bash

set -xeu -o pipefail

# shellcheck disable=SC2154  # from env.sh
cd "$release_dir"
# shellcheck disable=SC2154  # from env.sh
url="$("$extra_dir"/package/release_url.sh "$party_orders_repo" 'party_orders_.*\.zip')"
wget -nv "$url"
unzip party_orders*.zip mods/party_orders.ini mods/party_orders.dat
rm -f party_orders*.zip
