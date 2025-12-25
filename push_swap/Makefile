NAME 			= push_swap
BONUS_NAME 		= checker

SRCS_DIR 		= srcs
OBJS_DIR 		= objs

BONUS_DIR 		= bonus/srcs
BONUS_OBJS_DIR 	= bonus/objs

COMMON_SRCS = 	$(addprefix $(SRCS_DIR)/, init.c \
				checkings.c \
				ft_pile_functions1.c \
				ft_pile_functions2.c \
				operations1.c \
				operations2.c \
				sorting.c \
				sorting2.c \
				counting.c )

PUSH_SWAP_SRCS 	= $(SRCS_DIR)/push_swap.c

CHECKER_SRCS 	= $(addprefix $(BONUS_DIR)/, checker.c operations1_bonus.c operations2_bonus.c )

COMMON_OBJS 	= $(COMMON_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
PUSH_SWAP_OBJS 	= $(PUSH_SWAP_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o) $(COMMON_OBJS)
CHECKER_OBJS 	= $(CHECKER_SRCS:bonus/$(SRCS_DIR)/%.c=$(BONUS_OBJS_DIR)/%.o) $(COMMON_OBJS)

LIBFT_DIR 		= libft
LIBFT 			= libft/libft.a

FLAGS 			= -Wall -Wextra -Werror -g3

INCLUDES 		= -I includes -I $(LIBFT_DIR)/includes -I $(BONUS_DIR)/includes

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS) $(LIBFT)
	@cc $(FLAGS) -o $@ $^ -L libft -lft
	@echo "PUSH_SWAP COMPILED"

$(BONUS_NAME): $(CHECKER_OBJS) $(LIBFT)
	@cc $(FLAGS) -o $@ $^ -L libft -lft
	@echo "CHECKER COMPILED"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@cc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	@cc $(FLAGS) $(INCLUDES) -c -o $@ $<

bonus: $(NAME) $(BONUS_NAME)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJS_DIR) $(BONUS_OBJS_DIR)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
