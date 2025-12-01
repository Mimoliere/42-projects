NAME = get_next_line

SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = $(addprefix $(SRCS_DIR)/, get_next_line.c \
						get_next_line_utils.c \
						main.c)

BONUS_SRCS = $(addprefix $(SRCS_DIR)/, get_next_line_bonus.c \
								get_next_line_utils_bonus.c \
								main.c)

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

BONUS_OBJS = $(BONUS_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)
	@echo "COMPILED SUCCESSFULLY"

bonus: $(OBJS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(BONUS_OBJS)
	@echo "COMPILED SUCCESSFULLY"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -f $(OBJS)
	@echo "CLEANED"

fclean: clean
	@rm -f $(NAME)

re: fclean all