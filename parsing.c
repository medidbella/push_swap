/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:40 by midbella          #+#    #+#             */
/*   Updated: 2024/04/18 22:34:21 by midbella         ###   ########.fr       */
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
	int	index;

	stk->tab = malloc(sizeof(t_blk) * (nb));
	if (!stk->tab)
		error_handler(strs, NULL);
	stk->size = nb;
	index = 0;
	while (index < nb)
	{
		if (my_strlen(strs[index]) > 12)
			error_handler(NULL, stk->tab);
		stk->tab[index].num = my_atoi(strs[index], stk->tab);
		index++;
	}
	free_args(strs, nb);
	double_check(stk);
}

int	number_checker(char **strs)
{
	int	str_iter;
	int	char_iter;
	int	guarder;

	str_iter = 0;
	while (strs[str_iter])
	{
		if (strs[str_iter][0] == '\0')
			return (0);
		guarder = 0;
		char_iter = 0;
		while (strs[str_iter][char_iter])
		{
			if (what_is_it(strs[str_iter][char_iter], 0) && guarder > 0)
				return (0);
			if (what_is_it(strs[str_iter][char_iter], 3))
				guarder++;
			else
				return (0);
			char_iter++;
		}
		str_iter++;
	}
	return (1);
}

int	is_sorted(t_blk *blk, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (blk[index].num > blk[index + 1].num)
			return (0);
		index++;
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
