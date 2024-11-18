#!/bin/sh

set -e

cd "$(dirname "$0")"/..  || exit

LAB=$1

echo "Starting Compilation Database Generator..."
echo "Got lab: '$LAB'"
echo "Got STM32CubeIDE install path: '$CUBE_IDE_PATH'"

if [ -z "$CUBE_IDE_PATH" ]; then
    echo "CUBE_IDE_PATH not found."
    exit 1
fi

PROJECT_DIR="lab/$LAB/project"

python3 ci/compile_commands.py \
    --project_dir="$PROJECT_DIR" \
    --install_dir="$CUBE_IDE_PATH" > "$PROJECT_DIR/compile_commands.json"

echo "Compilation Database was generated!"
