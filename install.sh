#!/bin/sh

set -e

NAME="libtyctest.a"
INSTALL_DIR=$(pwd)
TMP_DIR="$INSTALL_DIR"/'tyctest.tmpdir'
PROJECT_DIR=$TMP_DIR

mkdir -p $TMP_DIR

echo "

Installing PATH \`$INSTALL_DIR\`

Major dependency programs when install:
 make
 gcc (named cc)
 git
"

function clean() {
	cd $INSTALL_DIR
	rm -rf "${INSTALL_DIR}/libs/$NAME"
	rm -rf "${INSTALL_DIR}/libs/libtyctest_main.a"
	rm -rf "${INSTALL_DIR}/includes/tyctest"
	rm -rf "${INSTALL_DIR}/bin/uninstall_tyctest.sh"
	rm -rf $TMP_DIR
	echo "install fail."
}
trap clean ERR

git clone git@github.com:PalmNeko/tyCtest_tool.git $TMP_DIR

cd "$PROJECT_DIR"

make
make libtyctest_main.a

mkdir -p "${INSTALL_DIR}/includes/tyctest"
mkdir -p "${INSTALL_DIR}/libs/"
mkdir -p "${INSTALL_DIR}/bin/"

cp unsintall_tyctest.sh "${INSTALL_DIR}/bin"
cp "$NAME" "${INSTALL_DIR}/libs"
cp libtyctest_main.a "${INSTALL_DIR}/libs"

HEADERS=$(find . -type f -name "*.h")
for HEADER in $HEADERS
	do cp "${HEADER}" "${INSTALL_DIR}/includes/tyctest"
done

echo '
installd.

For Usage :
	ex:
		gcc -I includes/tyctest mytest.c -o test -L libs -l tyctest_main -l tyctest
		./test

sample:
```c : mytest.c
#include <tyctest.h>

TEST(Title, Section) {
	ASSERT_EQ(0, 0);
	EXPECT_NE(3, 3); // output error
	ASSERT_NE(3, 3); // runnning
	EXPECT_NE(3, 3); // not runnning
}
```

For uninstall :
	please remove `include/tyctest` libs/libtyctest_main.a and libs/libtyctest.a.

For update :
	reinstall or uninstall to install.

Have a good test day.
'
rm -rf "$TMP_DIR"
