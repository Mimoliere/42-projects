NAME = cub3D

SRCS = $(addprefix srcs/,   cub3D.c \
							ft_parsing_utils1.c \
							ft_parsing_utils2.c \
							ft_parsing_utils3.c \
							ft_parsing_utils4.c \
							ft_parsing_utils5.c \
							ft_free.c \
							init.c \
							my_mlx.c \
							drawing.c \
							render_rect.c \
							dda.c \
							dda_2.c \
							draw_ray.c \
							rays.c \
							rays_2.c \
							texture_init.c \
							movements.c \
							tools.c)

OBJS = $(SRCS:srcs/%.c=objs/%.o)

LIBFT = includes/libft/libft.a

MLX = includes/mlx/libmlx_Linux.a

FLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -Imlx

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@cc $(FLAGS) -o $(NAME) $(OBJS) -L includes/libft -Iincludes -Iincludes/mlx -Lincludes/mlx -lft $(MLX) -lXext -lX11 -lm
	@echo "COMPILED"

objs/%.o: srcs/%.c
	@mkdir -p objs
	@cc $(FLAGS) -c -o $@ $< $(INCLUDES)

$(LIBFT):
	@$(MAKE) -C includes/libft

$(MLX):
	@$(MAKE) -C includes/mlx

clean:
	@rm -rf objs
	@$(MAKE) -C includes/libft clean
	@echo "CLEANED"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re