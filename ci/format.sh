#!/bin/sh

set -e

cd "$(dirname "$0")"/..  || exit

LAB=$1
MODE=$2

echo "Starting Formatter..."
echo "Got LAB: '$LAB'"
echo "Got MODE: '$MODE'"

PROJECT_DIR="lab/$LAB/project"

if [ "$MODE" = "fix" ]; then
  echo "Formatting code..."
  find "$PROJECT_DIR" -iname '*.hpp' -o -iname '*.cpp' \
  | xargs clang-format -i --fallback-style=Google --verbose
fi

echo "Check formatting."
find "$PROJECT_DIR" -iname '*.hpp' -o -iname '*.cpp' \
| xargs clang-format -Werror --dry-run --fallback-style=Google --verbose

echo "Done!"
