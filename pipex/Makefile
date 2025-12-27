NAME = pipex

SRCS = 	$(addprefix srcs/, \
						pipex.c \
						pipex_utils.c \
						pipex_utils_2.c )

OBJS = $(SRCS:srcs/%.c=objs/%.o)

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cc $(FLAGS) -o $@ $^ -L libft -lft
	@echo "COMPILED"

objs/%.o: srcs/%.c
	@mkdir -p objs
	@cc $(FLAGS) -I libft -c $< -o $@

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@rm -rf objs
	@$(MAKE) -C libft clean
	@echo "CLEANED"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
