# Colors
RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
RED = \033[31m

# Source Files
SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \
		ft_printf_utils3.c \
		parsing.c \
		render_add.c \
		render_char.c \
		render_hex.c \
		render_nbr.c \
		render_str.c \
		render_str2.c \
		render_unint.c \
		get_next_line.c \
		get_next_line_utils.c

SRCS_BONUS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Commands
RM = rm -rf
AR = ar rc

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$$(echo -e '$(BLUE)Creating library $(NAME)...$(RESET)')"
	@$(AR) $(NAME) $(OBJS)
	@echo "$$(echo -e '$(GREEN)✔ Library $(NAME) created.$(RESET)')"

%.o: %.c
	@echo "$$(echo -e '$(YELLOW)Compiling $<...$(RESET)')"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	@echo "$$(echo -e '$(BLUE)Creating library $(NAME) with bonus files...$(RESET)')"
	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "$$(echo -e '$(GREEN)✔ Library $(NAME) with bonus created.$(RESET)')"

clean:
	@echo "$$(echo -e '$(RED)Cleaning object files...$(RESET)')"
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$$(echo -e '$(GREEN)✔ Object files removed.$(RESET)')"

fclean: clean
	@echo "$$(echo -e '$(RED)Removing library $(NAME)...$(RESET)')"
	@$(RM) $(NAME)
	@echo "$$(echo -e '$(GREEN)✔ Library $(NAME) and object files removed.$(RESET)')"

re: fclean all

.PHONY: all clean fclean re bonus
