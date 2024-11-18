# Colors
RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
RED = \033[31m

# Executables
SERVER = server
CLIENT = client

# Compiler and Flags
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g -I./include

# Commands
RM = rm -rf

# Source Files
SRCS_SERVER = srcs/minitalk_server.c srcs/minitalk_utils.c
SRCS_CLIENT = srcs/minitalk_client.c srcs/minitalk_utils.c

# Library
LIBFT = libft/libft.a

# Targets
all: $(SERVER) $(CLIENT)

$(SERVER): $(SRCS_SERVER) $(LIBFT)
	@echo "$$(echo -e '$(BLUE)Compiling $(SERVER)...$(RESET)')"
	@$(CC) $(CFLAGS) $(SRCS_SERVER) $(LIBFT) -o $(SERVER)
	@echo "$$(echo -e '$(GREEN)✔ $(SERVER) executable created.$(RESET)')"

$(CLIENT): $(SRCS_CLIENT) $(LIBFT)
	@echo "$$(echo -e '$(BLUE)Compiling $(CLIENT)...$(RESET)')"
	@$(CC) $(CFLAGS) $(SRCS_CLIENT) $(LIBFT) -o $(CLIENT)
	@echo "$$(echo -e '$(GREEN)✔ $(CLIENT) executable created.$(RESET)')"

$(LIBFT):
	@echo "$$(echo -e '$(YELLOW)Building libft library...$(RESET)')"
	@$(MAKE) -C libft bonus
	@echo "$$(echo -e '$(GREEN)✔ libft.a created.$(RESET)')"

clean:
	@echo "$$(echo -e '$(RED)Cleaning executables and object files...$(RESET)')"
	@$(RM) $(SERVER) $(CLIENT)
	@$(MAKE) clean -C libft
	@echo "$$(echo -e '$(GREEN)✔ Executables and object files removed.$(RESET)')"

fclean: clean
	@echo "$$(echo -e '$(RED)Removing libft.a...$(RESET)')"
	@$(RM) $(LIBFT)
	@$(MAKE) fclean -C libft
	@echo "$$(echo -e '$(GREEN)✔ Full clean complete.$(RESET)')"

re: fclean all

.PHONY: all clean fclean re
