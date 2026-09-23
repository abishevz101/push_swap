#include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;

typedef struct s_flags
{
	char	flag;
	int		bench;
	int		f_count;
} t_flags;

int parsing(int argc, char **argv, t_stack **stack, t_flags *flags);
void print_error();
int	ft_strcmp(char *s1, char *s2);