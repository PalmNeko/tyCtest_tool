# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 15:29:13 by tookuyam          #+#    #+#              #
#    Updated: 2023/10/29 16:54:40 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = "test"
ifeq ($(MAKECMDGOALS), debug)
	NAME = "test"
	CFLAGS += -g -fsanitize=address
endif

ifeq ($(OS),Windows_NT)
	CFLAGS += -D WINDOWS
endif

# directories
MAKEFILE_DIR = $(dir $(lastword $(MAKEFILE_LIST)))
PROJECT_ROOT = $(MAKEFILE_DIR)
SRC_DIR = $(PROJECT_ROOT)/srcs
OBJ_DIR = $(PROJECT_ROOT)/objs
TEST_DIR = $(PROJECT_ROOT)/tests
INC_DIRS = $(dir $(INCS))

$(shell mkdir -p $(OBJ_DIR))

# compiles
CC = cc
INCS = $(shell find $(PROJECT_ROOT) -type f -name "*.h")
CFLAGS += -Wall -Werror -Wextra $(addprefix -I,$(INC_DIRS))

SRC =  $(shell find $(SRC_DIR) -name "*.c")
TEST = $(shell find $(TEST_DIR) -name "*.c")
COMPILE_SRC = $(SRC) $(TEST)
COMPILE_OBJ = $(COMPILE_SRC:.c=.o)

# all rule
all: $(NAME)
# all:

# make files rules
$(NAME): $(COMPILE_OBJ) $(INCS)
	$(CC) $(CFLAGS) -o $(NAME) $(filter %.o,$^)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# .PHONY rules
clean:
	$(RM) $(COMPILE_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
