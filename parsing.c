/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:40 by midbella          #+#    #+#             */
/*   Updated: 2024/04/17 22:09:48 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	double_check(t_stack *stk)
{
	int	start;
	int	iter;

	start = 0;
	while (start < stk->size - 1)
	{
		iter = start + 1;
		while (iter <= stk->size - 1)
		{
			if (stk->tab[start].num == stk->tab[iter].num)
				error_handler(NULL, stk->tab);
			iter++;
		}
		start++;
	}
}

void	initializer(t_stack *stk, char **strs, int nb)
{
	int	i;

	stk->tab = malloc(sizeof(t_blk) * (nb));
	if (!stk->tab)
		error_handler(strs, NULL);
	stk->size = nb;
	i = 0;
	while (i < nb)
	{
		stk->tab[i].rank = -1;
		i++;
	}
	i = 0;
	while (i < nb)
	{
		if (my_strlen(strs[i]) > 12)
			error_handler(NULL, stk->tab);
		stk->tab[i].num = my_atoi(strs[i], stk->tab);
		i++;
	}
	free_args(strs, nb);
	double_check(stk);
}

int	number_checker(char **strs)
{
	int	j;
	int	i;
	int	sign;

	j = 0;
	while (strs[j])
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

int	is_sorted(t_blk *blk, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (blk[i].num > blk[i + 1].num)
			return (0);
		i++;
	}
	return (1);
}

void	free_args(char **args, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		free(args[i++]);
		i++;
	}
	free(args);
}
