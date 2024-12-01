# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ywakamiy <ywakamiy@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 23:44:57 by ywakamiy          #+#    #+#              #
#    Updated: 2024/12/01 09:02:25 by ywakamiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined
SRC_DIR = src
BUILD_DIR = build
INCL_DIR = include

SRCS = $(SRC_DIR)/ft_printf.c \
       $(SRC_DIR)/ft_putchar.c \
       $(SRC_DIR)/ft_putnbr.c \
       $(SRC_DIR)/ft_putnbr_base.c \
       $(SRC_DIR)/ft_putstr.c \
       $(SRC_DIR)/help.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
INCL = -I$(INCL_DIR)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/ft_printf.h
		mkdir -p $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

clean:
		rm -rf $(BUILD_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

