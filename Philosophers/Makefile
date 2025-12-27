NAME = philo

SRCS = $(addprefix srcs/, \
						philo.c \
						errors.c \
						tools.c \
						checks.c \
						manage.c \
						monitoring.c \
						actions.c )

OBJS = $(SRCS:srcs/%.c=objs/%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(FLAGS) -o $@ $^
	@echo "PHILO COMPILED"

objs/%.o: srcs/%.c
	@mkdir -p objs
	@cc $(FLAGS) -c -o $@ $<

bonus: $(NAME)

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus