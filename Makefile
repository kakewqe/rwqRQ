# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:32:19 by zachamou          #+#    #+#              #
#    Updated: 2023/10/19 00:31:10 by zachamou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinc -Iinc/libft

LIBFT_DIR = inc/libft
LIBFT_SRC = inc/libft/ft_split.c inc/libft/ft_putendl_fd.c inc/libft/ft_isdigit.c inc/libft/ft_isspace.c
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

PUSH_SWAP_SRC =  push_swap.c \
				op_1.c \
				op_2.c \
				op_3.c \
				op_4.c \
				parsing.c \
				list.c \
				utile_sort.c \
				utile.c \
				index_stack.c \
				sort/sort2to5.c \
				sort/radix_sort.c

				
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
PUSH_SWAP = push_swap

all: $(LIBFT) $(PUSH_SWAP)

$(LIBFT): $(LIBFT_OBJ)
	ar rc $@ $^
	ranlib $@

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(LIBFT)
	$(CC) $(PUSH_SWAP_OBJ) $(LIBFT) -lm -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(PUSH_SWAP) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
