# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 12:06:31 by yuxchen           #+#    #+#              #
#    Updated: 2024/08/23 16:59:19 by yuxchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC         = gcc
CFLAGS     = -Wall -Wextra -Werror
RM         = rm -f

# Files
SRCS       = get_next_line.c get_next_line_utils.c
OBJS       = $(SRCS:.c=.o)

# Header files
HEADERS    = get_next_line.h

# Output
NAME       = get_next_line.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# Test rule (optional)
# Uncomment and customize the main.c file for testing
# test: $(NAME)
# 	$(CC) $(CFLAGS) -o test_main $(SRCS) main.c
# 	./test_main

.PHONY: all clean fclean re
