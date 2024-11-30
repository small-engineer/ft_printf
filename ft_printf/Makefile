# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 23:44:57 by ywakamiy          #+#    #+#              #
#    Updated: 2024/12/01 00:27:19 by ywakamiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INCL_DIR = include

SRCS = $(SRC_DIR)/ft_printf.c \
       $(SRC_DIR)/ft_putchar.c \
       $(SRC_DIR)/ft_putnbr.c \
       $(SRC_DIR)/ft_putnbr_base.c \
       $(SRC_DIR)/ft_putstr.c \
       $(SRC_DIR)/libft.c
OBJS = $(SRCS:.c=.o)
INCL = -I$(INCL_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCL_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
