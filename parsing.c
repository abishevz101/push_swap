/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:41:07 by vkyryche          #+#    #+#             */
/*   Updated: 2026/10/01 17:22:20 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int p_number(char *nptr, t_stack **stack_a)
{
	int		sign;
	long	number;
	int		is_empty;

	sign = 1;
	number = 0;
	is_empty = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		is_empty = 0;
		number = number * 10 + (*nptr++ - '0') * sign;
		if (number > INT_MAX || number < INT_MIN)
			return (1);
	}
	if (*nptr || is_empty || is_duplicate(stack_a, number))
		return (1);
	return (0);
}

int p_flags(char *argument, t_flags *flags)
{
	if (!ft_strcmp(argument, "--simple"))
        flags->flag = 's';
    else if (!ft_strcmp(argument, "--medium"))
        flags->flag = 'm';
    else if (!ft_strcmp(argument, "--complex"))
        flags->flag = 'c';
    else if (!ft_strcmp(argument, "--adaptive"))
        flags->flag = 'a';
    else if (!ft_strcmp(argument, "--bench"))
    {
        flags->bench = 1;
        return (0);
    }
    else
        return (1);
    flags->f_count++;
    return (0);
}

int parsing(int argc, char **argv, t_stack **stack_a, t_flags *flags)
{
	char **argument;
	int i;

	while (--argc)
	{
		argument = ft_split(argv[argc], ' ');
		i = 0;
		while(argument[i])
            i++;
		while(--i >= 0 || !argument[0])
		{
			if (!argument[0] || ((p_flags(argument[i], flags)
				|| flags->f_count > 1))
				&& p_number(argument[i], stack_a))
			{
				free_split(argument);
				free_stack(stack_a);
				return (1);
			}
		}
		free_split(argument);
	}
	return 0;
}
