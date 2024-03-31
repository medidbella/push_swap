/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:40 by midbella          #+#    #+#             */
/*   Updated: 2024/03/31 23:34:27 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	double_check(t_stack *stk)
{
	int start;
	int	i;
	int iter;

	start = 0;
	while (start < stk->size - 1)
	{
		i = start;
		iter = start + 1;
		while (iter <= stk->size - 1)
		{
			if (stk->tab[i].num == stk->tab[iter].num)
				error_handler(NULL, stk->tab);
			iter++;
		}
		start++;
	}
}

void	initializer(t_stack *stk , char **strs, int nb)
{
	int	i;

	stk->tab = malloc(sizeof(t_blk) * (nb));
	stk->size = nb;
	i = 0;
	while (i < nb)
	{
		stk->tab[i].rank = i;
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
	double_check(stk);
	i = 0;
	while (i < nb)
		free(strs[i++]);
	free(strs);
}
