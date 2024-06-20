# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 15:29:13 by tookuyam          #+#    #+#              #
#    Updated: 2024/06/20 15:16:00 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME 		= test
CFLAGS 		+= -Wall -Werror -Wextra -MMD -MP
CC 			= cc
SRC_DIR	 	= .
CFLAGS 		+= -Wall -Werror -Wextra -I..
SRCS 		= $(shell find $(SRC_DIR) -name "*.c")
OBJS 		= $(SRCS:.c=.o)
DEPS 		= $(SRCS:.c=.d)
LDFLAGS		= -L../
LDLIBS		= -ltyctest_main -ltyctest

# all rule
all: $(NAME)

# .PHONY rules
clean:
	find . -name "*.o" -delete
	find . -name "*.d" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

# make files rules
$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@


../libtyctest_main.a:
	make -C ..

../libtyctest.a:
	make -C ..

-include $(DEPS)