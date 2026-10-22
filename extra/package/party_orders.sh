#!/bin/bash

set -xeu -o pipefail

cd "$RELEASE_DIR"
url="$("$EXTRA_DIR"/package/release_url.sh "$PARTY_ORDERS_REPO" 'party_orders_.*\.zip')"
wget -nv "$url"
unzip party_orders*.zip mods/party_orders.ini mods/party_orders.dat
rm -f party_orders*.zip
