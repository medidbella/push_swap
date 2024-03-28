/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:18:17 by midbella          #+#    #+#             */
/*   Updated: 2024/03/27 02:56:00 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranker(t_blk *blk, int size)
{
	int j;
	int	i;
	int	tmp;

	i = -1;
	while (i++ < size)
		blk[i].rank = i;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if ((blk[i].num > blk[j].num && blk[i].rank < blk[j].rank) || 
				(blk[i].num < blk[j].num && blk[i].rank > blk[j].rank))
			{
				tmp = blk[i].rank;
				blk[i].rank = blk[j].rank;
				blk[j].rank = tmp;
			}
			j++;
		}
		i++;
	}
}


int	number_checker(int nb, char **strs)
{
	int	j;
	int	i;
	int	sign;

	j = 0;
	while (j <= nb)
	{
		if (strs[j][0] == '\0')
			return (0);
		sign = 0;
		i = 0;
		while (strs[j][i])
		{
			if (is_what(strs[j][i], 0) && sign > 0)
				return (0);
			if (is_what(strs[j][i], 3))
				sign++;
			else
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	counter(char **args, int nb)
{
	int	count;
	int	i;
	int	j;

	j = 1;
	count = 0;
	while (j <= nb)
	{
		i = 0;
		if (!is_what(args[j][0], 1))
			count++;
		while (args[j][i])
		{
			if (!is_what(args[j][i], 1) && is_what(args[j][i - 1], 1))
				count++;
			i++;
		}
		j++;
	}
	return (count);
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
