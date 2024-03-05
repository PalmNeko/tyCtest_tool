# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 15:29:13 by tookuyam          #+#    #+#              #
#    Updated: 2023/11/01 14:29:50 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = libtyctest.a
TEST = test
ifeq ($(findstring test,$(MAKECMDGOALS)), test)
	COMPILE_SRC += $(TEST_SRC)
endif

ifeq ($(OS),Windows_NT)
	CFLAGS += -D WINDOWS
	TEST = test.exe
else
	CFLAGS += -D MAC
	TEST = test
endif
CFLAGS += -MMD -MP

# directories
PROJECT_ROOT = .
SRC_DIR = $(PROJECT_ROOT)/srcs
OBJ_DIR = $(PROJECT_ROOT)/objs
TEST_DIR = $(PROJECT_ROOT)/tests
INC_DIRS = $(dir $(INCS))

$(shell mkdir -p $(OBJ_DIR))

# compiles
CC = cc
INCS = $(shell find $(PROJECT_ROOT) -type f -name "*.h")
CFLAGS += -Wall -Werror -Wextra -std=c17 $(addprefix -I,$(INC_DIRS))

SRC =  $(shell find $(SRC_DIR) -name "*.c")
TEST_SRC = $(shell find $(TEST_DIR) -name "*.c")
COMPILE_SRC += $(SRC)
COMPILE_OBJ = $(COMPILE_SRC:.c=.o)
COMPILE_DEPENDS = $(COMPILE_SRC:.c=.d)

# all rule
all: $(NAME)

-include $(COMPILE_DEPENDS)

# make files rules
$(NAME): $(COMPILE_OBJ)
	ar rcs $(NAME) $(filter %.o,$^)

libtyctest_main.a: tests/main.o
	ar rcs libtyctest_main.a $(filter %.o,$^)

$(TEST): $(COMPILE_OBJ)
	$(CC) $(CFLAGS) -o $@ $(filter %.o,$^)

# .PHONY rules
clean:
	find . -name "*.o" -delete
	find . -name "*.d" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
