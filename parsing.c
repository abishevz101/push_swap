/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:41:07 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/23 21:30:39 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void free_split(char **split_arr)
{
    int i;

	i = 0;
    while (split_arr[i])
        free(split_arr[i++]);
    free(split_arr);
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
        return (1);
    }
    else
        return (0);
    flags->f_count++;
    return (1);
}

int parsing(int argc, char **argv, t_stack **stack, t_flags *flags)
{
	char **argument;
	int i;

	while (--argc)
	{
		argument = ft_split(argv[argc], ' ');
		i = 0;
		while(argument[i] != NULL)
            i++;
		while(--i >= 0)
		{
			if ((!p_flags(argument[i], flags) || flags->f_count > 1)
				&& !number(argument[i], stack))
			{
				// function that cleans the linked list
				free_split(argument);
				// Print "Error\n" to stderr
				return (1);
			}
		}
		free_split(argument);
	}
	return 0;
}
