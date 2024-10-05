#!/bin/sh

set -e

cd "$(dirname "$0")"/..  || exit

LAB=$1

echo "Starting Configuration Master..."
echo "Got lab: '$LAB'"

echo "Copy .clang-format"
cp config/.clang-format "lab/$LAB/project/.clang-format"

echo "Copy .clangd"
cp config/.clangd "lab/$LAB/project/.clangd"

echo "Generate compile_commands.json"
sh ci/compile_commands.sh "$LAB"
