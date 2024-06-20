NAME = libtyctest_main.a
SRCS = srcs/main.c
CC = cc
CFLAGS += -Wall -Werror -Wextra -std=c17 -MMD -MP -I.
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

ifeq ($(OS),Windows_NT)
	CFLAGS += -D WINDOWS
else ifeq ($(shell uname),Linux)
else
	CFLAGS += -D MAC
endif

# all rule
all: $(NAME)

# .PHONY rules
clean:
	find . -name "*.o" -delete
	find . -name "*.d" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

show:
	@echo "SRCS:"
	@echo "$(SRCS)"
	@echo "OBJS:"
	@echo "$(OBJS)"
	@echo "CFLAGS: $(CFLAGS)"

.PHONY: all clean fclean re

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

-include $(DEPS)