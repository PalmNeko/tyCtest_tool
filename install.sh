#!/bin/sh

NAME="libtyctest.a"
INSTALL_DIR=$(pwd)
PROJECT_DIR=$(dirname "$0")

cd "$PROJECT_DIR" || (echo 'failure change directory' ; exit 1)

make || (echo 'compile error' ; exit 1)
make libtyctest_main.a || (echo 'compile error' ; exit 1)

mkdir -p "${INSTALL_DIR}/includes/tyctest"
mkdir -p "${INSTALL_DIR}/libs/"

cp "$NAME" "${INSTALL_DIR}/libs"
cp libtyctest_main.a "${INSTALL_DIR}/libs"

HEADERS=$(find . -type f -name "*.h")
for HEADER in $HEADERS
	do cp "${HEADER}" "${INSTALL_DIR}/includes/tyctest"
done

