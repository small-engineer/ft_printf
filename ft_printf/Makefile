NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined
SRC_DIR = src
BUILD_DIR = build
INCL_DIR = include
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRC_DIR)/ft_printf.c \
       $(SRC_DIR)/ft_putchar.c \
       $(SRC_DIR)/ft_putnbr.c \
       $(SRC_DIR)/ft_putnbr_base.c \
       $(SRC_DIR)/ft_putstr.c \
       $(SRC_DIR)/help.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
INCL = -I$(INCL_DIR) -I$(LIBFT_DIR)

# Colors
RESET = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)[BUILD] Creating archive: $(NAME)$(RESET)"
	@ar rcs $(NAME) $(OBJS)
	@ar rcs $(NAME) $(LIBFT_DIR)/*.o

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCL_DIR)/ft_printf.h
	@echo "$(BLUE)[BUILD] Compiling: $<$(RESET)"
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

$(LIBFT):
	@echo "$(YELLOW)[BUILD] Building libft$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

clean:
	@echo "$(RED)[CLEAN] Removing build directory$(RESET)"
	@rm -rf $(BUILD_DIR)
	@echo "$(RED)[CLEAN] Cleaning libft$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "$(RED)[FCLEAN] Removing $(NAME)$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

