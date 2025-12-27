NAME 		= so_long

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS		= $(addprefix $(SRCS_DIR)/, so_long.c errors.c checks.c images.c map.c move.c)

OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT_DIR   = includes/libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = includes/mlx
MLX         = $(MLX_DIR)/libmlx_Linux.a

FLAGS       = -Wall -Wextra -Werror -g
INCLUDES    = -I includes -I $(MLX_DIR) -I $(LIBFT_DIR)/includes

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@cc $(FLAGS) -o $@ $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
	@echo "COMPILED"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@cc $(FLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "CLEANED"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re