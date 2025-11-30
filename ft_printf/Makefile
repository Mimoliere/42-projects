NAME = ft_printf

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, ft_printf.c ft_printf_functions.c main.c)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAG = -Wall -Wextra -Werror
INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) $(INCLUDES) -o $(NAME) $(OBJS)
	@echo "COMPILED SUCCESSFULLY"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -f $(OBJS)
	@echo "CLEANED"

fclean: clean
	@rm -f $(NAME)

re: fclean all
