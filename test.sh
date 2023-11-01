#!/bin/sh

cd $(dirname "$0") || (echo 'error change directory' ; exit 1)
make

cd tests || (echo 'error change diectory' ; exit 1)
sh ../install.sh

cc -Wall -Wextra -Werror -Iincludes/tyctest -o test libs/libtyctest.a *.c

./test
