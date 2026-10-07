/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabishev <zabishev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 20:42:10 by vkyryche          #+#    #+#             */
/*   Updated: 2026/10/07 21:19:49 by zabishev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_flags
{
	char	flag;
	int		bench;
	int		f_count;
}	t_flags;

typedef struct s_bench
{
	char	strategy;
	char	*complexity;
	double	disorder;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		bench;
}	t_bench;

int		parsing(int argc, char **argv, t_stack **stack, t_flags *flags);
int		ft_strcmp(char *s1, char *s2);
void	free_split(char **split_arr);
int		is_duplicate(t_stack **stack, int number);

void	free_stack(t_stack **stack);
int		add_to_stack(t_stack **head, int value);
size_t	stack_size(t_stack *head);

void	chunk_sort(t_stack **a, t_stack **b, t_bench *bench);
void	min_extraction(t_stack **a, t_stack **b, t_bench *bench);
void	radix_sort(t_stack **a, t_stack **b, t_bench *bench);

void	sa(t_stack **a, int rule, t_bench *bench);
void	sb(t_stack **b, int rule, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, int rule, t_bench *bench);
void	rb(t_stack **b, int rule, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, int rule, t_bench *bench);
void	rrb(t_stack **b, int rule, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

void	display_bench(t_bench *bench);

void	rotate_to_index(t_stack **a, int index, t_bench *bench);
int		find_in_chunk(t_stack *a, int min, int max);
void	rotate_min_to_top(t_stack **a, t_bench *bench);
int		chnk_max(long long int size, long long int chunk);
int		chnk_min(long long int size, long long int chunk);
int		int_sqrt(int n);
void	range_numbers(t_stack *a);
int	count_smaller(t_stack *a, int target)ж

#endif