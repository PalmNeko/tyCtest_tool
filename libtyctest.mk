# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libtyctest.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 15:29:13 by tookuyam          #+#    #+#              #
#    Updated: 2024/06/20 15:40:26 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = libtyctest.a
CC = cc
CFLAGS += -Wall -Werror -Wextra -std=c17 -MMD -MP -I.
SRC_DIR = srcs
SRCS = $(shell find $(SRC_DIR) -name "*.c" -not -name "main.c")
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

clean:
	rm -f $(OBJS) $(DEPS)

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
	ar rcs $(NAME) $(OBJS)

-include $(DEPS)
