#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

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
// void print_error();
int	ft_strcmp(char *s1, char *s2);
void free_split(char **split_arr);
int is_duplicate(t_stack **stack, int number);
void	free_stack(t_stack **stack);
int	add_to_stack(t_stack **head, int value);
void	min_extraction(t_stack **a, t_stack **b);
size_t	stack_size(t_stack *head);

void	sa(t_stack **a, int rule);
void	sb(t_stack **b, int rule);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int rule);
void	rb(t_stack **b, int rule);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int rule);
void	rrb(t_stack **b, int rule);
void	rrr(t_stack **a, t_stack **b);


#endif