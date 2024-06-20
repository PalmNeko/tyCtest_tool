
LIBTYCTEST_MAIN = libtyctest_main.a
LIBTYCTEST = libtyctest.a

all: $(LIBTYCTEST_MAIN) $(LIBTYCTEST)

clean:
	make -f $(LIBTYCTEST_MAIN:.a=.mk) clean
	make -f $(LIBTYCTEST:.a=.mk) clean

fclean: clean
	make -f $(LIBTYCTEST_MAIN:.a=.mk) fclean
	make -f $(LIBTYCTEST:.a=.mk) fclean

re: fclean all

debug: CFLAGS += -g -O0
debug: re

%.a: %.mk
	CFLAGS="$(CFLAGS)" make -f $^