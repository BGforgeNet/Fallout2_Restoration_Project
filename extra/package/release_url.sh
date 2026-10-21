#!/bin/bash

# Print the download URL of the one asset in a GitHub repository's latest release whose file name matches a pattern.
# Usage: release_url.sh <owner/repo> <extended regex matching the whole asset name>
# GITHUB_TOKEN, when set, authenticates the request: anonymous API calls are rate limited per IP, which CI runners share.

set -eu -o pipefail

repo="$1"
pattern="$2"

auth=()
if [[ -n "${GITHUB_TOKEN:-}" ]]; then
    auth=(-H "Authorization: Bearer $GITHUB_TOKEN")
fi

if ! release="$(curl -sS -f --retry 3 "${auth[@]}" "https://api.github.com/repos/$repo/releases/latest")"; then
    echo "release_url.sh: cannot read the latest release of $repo" >&2
    exit 1
fi

urls="$(awk -F '"' '/"browser_download_url"/ {print $4}' <<<"$release")"
# Through the environment, not awk -v, which would turn the pattern's backslash escapes into plain characters.
matches="$(ASSET_PATTERN="^($pattern)\$" awk -F / '$NF ~ ENVIRON["ASSET_PATTERN"]' <<<"$urls")"
count="$(awk 'NF {n++} END {print n + 0}' <<<"$matches")"
if [[ "$count" != 1 ]]; then
    echo "release_url.sh: $count assets of the latest $repo release match '$pattern'; assets:" >&2
    echo "$urls" | awk -F / '{print "  " $NF}' >&2
    exit 1
fi
echo "$matches"
