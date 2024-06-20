# tyCtest

test tool for lang c.(42Tokyo)

# Install

run commands (If make public repository, will replace curl)

```
git clone git@github.com:PalmNeko/tyCtest_tool.git tyCtest_tool
bash tyCtest_tool/install.sh
rm -rf tyCtest_tool
```

or

```
bash -c "$(curl https://raw.githubusercontent.com/PalmNeko/tyCtest_tool/master/install.sh)"
```

# Uninstall

1. delete `includes/tyctest` `libs/libtyctest_main.a` and `libs/libtyctest.a` in your install directory.

# Docs

[docs](./docs/index.md)

# Usage

compile your file with option:
* `-Iincludes/tyctest`

and library:
* `libs/libtyctest.a`
* `libs/libtyctest_main.a` (This contains the main file. If you prepare your own main dish, don't use it.)

ex:
`cc -Iincludes/tyctest my_test.c my_test1.c libs/libtyctest.a libs/libtyctest_main.a`
