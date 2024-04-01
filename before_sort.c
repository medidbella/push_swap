/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:18:17 by midbella          #+#    #+#             */
/*   Updated: 2024/04/01 23:36:55 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smalles_hepler(t_blk *blk, int size, int *index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (blk[i].rank == -1)
		{
			j++;
			*index = i;
		}
		i++;
	}
	return (j);
}

int	get_smallest(t_blk *blk, int size)
{
	int	index;
	int	i;
	int	j;

	j = get_smalles_hepler(blk, size, &index);
	if (j == 1)
		return (index);
	else if (j == 0)
		return (-1);
	j = 0;
	i = 0;
	while (j < size)
	{
		if ((blk[i].num > blk[j].num || blk[i].rank != -1)
			&& (blk[j].rank == -1))
			i = j;
		j++;
	}
	return (i);
}

void	ranker(t_blk *blk, int size)
{
	int	stp;
	int	r;

	r = 0;
	while (1)
	{
		stp = get_smallest(blk, size);
		if (stp == -1)
			break ;
		blk[stp].rank = r;
		r++;
	}
}

char	*split_and_fill(char *arg, int *ptr)
{
	char		*res;
	static int	x;
	int			l;
	int			h;

	if (*ptr == -1)
		x = 0;
	l = 0;
	while (is_what(arg[x], 1))
		x++;
	while (!is_what(arg[x], 1) && arg[x])
	{
		x++;
		l++;
	}
	h = x;
	*ptr = x;
	res = malloc(sizeof(char) * (l + 1));
	res[l] = 0;
	while (l >= 0)
		res[--l] = arg[--h];
	return (res);
}

char	**my_split(char **args, int nb)
{
	int		i;
	char	**res;
	int		c;
	int		l;

	i = 0;
	l = 0;
	c = counter(args, nb);
	res = malloc(sizeof(char *) * (c + 1));
	res[c] = NULL;
	c = 1;
	while (c <= nb)
	{
		res[i] = split_and_fill(args[c], &l);
		while (is_what(args[c][l], 1))
			l++;
		if (args[c][l] == '\0')
		{
			l = -1;
			c++;
		}
		i++;
	}
	return (res);
}
