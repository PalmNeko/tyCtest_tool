#!/bin/bash

set -e

function clean() {
	echo "install fail."
	exit 1
}
trap clean ERR

which git || (echo 'need which command' ; exit 1)
which make || (echo 'need make command' ; exit 1)

git clone git@github.com:PalmNeko/tyCtest_tool.git tyctest
cd tyctest
make

echo '
installd.

For Usage :
	ex:
		gcc -Ityctest mytest.c -o test -Ltyctest -l tyctest_main -l tyctest
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
	please remove `tyctest` directory

For update :
	reinstall or uninstall to install.

Have a good test day.
'
