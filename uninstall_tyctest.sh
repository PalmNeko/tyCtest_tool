#!/bin/sh

set -e

printf "Are you sure uninstall? (n/y) "
read YN

if [[ "$YN" != "y" ]] then
	exit 0
fi

rm -rf ../includes/tyctest
rm -f ../libs/libtyctest.a
rm -f ../libs/libtyctest_main.a
