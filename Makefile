CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = main.c \
		parsing.c \
		stack_management.c \
		the_rules.c \
		s_algorithm.c \
		m_algorithm.c \
		m_algorithm_help.c \
		c_algorithm.c \
		bench.c
NAME = push_swap
OBJS = $(FILES:.c=.o)

all : $(NAME)

libft/libft.a :
	$(MAKE) -C libft

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re : fclean all