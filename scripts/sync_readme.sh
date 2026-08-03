#!/bin/bash
set -e

TRACK_FILE="Contents.txt"
README="README.md"
START_MARKER="<!-- CONTENTS-START -->"
END_MARKER="<!-- CONTENTS-END -->"

if ! grep -q "$START_MARKER" "$README" 2>/dev/null; then
    echo -e "\n$START_MARKER\n$END_MARKER" >> "$README"
fi

awk -v start="$START_MARKER" -v end="$END_MARKER" -v txtfile="$TRACK_FILE" '
    $0 ~ start {print; while ((getline line < txtfile) > 0) print line; skip=1; next}
    $0 ~ end {skip=0}
    !skip {print}
' "$README" > tmp_readme.md && mv tmp_readme.md "$README"
