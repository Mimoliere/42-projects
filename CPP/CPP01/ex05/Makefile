NAME	= harl

SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes

SRCS	= $(addprefix $(SRCDIR)/, main.cpp Harl.cpp)
OBJS	= $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CC		= g++
CFLAGS	= -Werror -Wextra -Wall -std=c++98 -I $(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo COMPILED

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo CLEANED

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean