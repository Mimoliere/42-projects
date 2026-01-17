NAME = ex00

SRCS = megaphone.cpp

OBJS = $(SRCS:srcs/%.c=objs/%.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(FLAGS) -o $(NAME) $(OBJS)
	@echo "COMPILED"

objs/%.o: srcs/%.c
	@mkdir -p objs
	@cc $(FLAGS) -c -o $@ $<

clean:
	@rm -rf objs
	@echo "CLEANED"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re