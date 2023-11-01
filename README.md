# tyCtest

test tool for lang c.(42Tokyo)

# Install

1. download.
2. run `sh install.sh` at folder where you want to install.
	(create `includes/tyctest/*.h` and `libs/libtyctest.a`)
3. done.

# Uninstall

1. delete `includes/tyctest` `libs/libtyctest_main.a` and `libs/libtyctest.a` in your install directory.

# Docs

(./docs/index.md)[docs]

# Usage

compile your file with option:
* `-Iincludes/tyctest`

and library:
* `libs/libtyctest.a`
* `libs/libtyctest_main.a` (This contains the main file. If you prepare your own main dish, don't use it.)

ex:
`cc -Iincludes/tyctest my_test.c my_test1.c libs/libtyctest.a libs/libtyctest_main.a`
