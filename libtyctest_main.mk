NAME = libtyctest_main.a
SRCS = srcs/main.c
CC = cc
CFLAGS += -Wall -Werror -Wextra -std=c17 -MMD -MP
OBJS = $(SRCS:.c:.o)
DEPS = $(OBJS:.o:.d)

ifeq ($(OS),Windows_NT)
	CFLAGS += -D WINDOWS
else ifeq ($(uname),Linux)
else
	CFLAGS += -D MAC
endif

# all rule
all: $(NAME)

# make files rules
$(NAME): $(OBJS)
	ar rcs $@ $(OJBS)

# .PHONY rules
clean:
	find . -name "*.o" -delete
	find . -name "*.d" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)