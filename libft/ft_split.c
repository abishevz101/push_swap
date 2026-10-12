/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkyryche <vkyryche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:35:06 by vkyryche          #+#    #+#             */
/*   Updated: 2026/09/09 12:52:14 by vkyryche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_alloc(char *start, size_t size, char **arr, int index)
{
	arr[index] = malloc(size);
	if (!arr[index])
	{
		while (--index >= 0)
			free(arr[index]);
		free(arr);
		return (1);
	}
	ft_strlcpy(arr[index], start, size);
	return (0);
}

int	word_count(char const *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			word_count++;
		}
		else
			s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*start;
	int		index;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			if (word_alloc(start, s - start + 1, arr, index++))
				return (NULL);
		}
		else
			s++;
	}
	arr[index] = NULL;
	return (arr);
}
