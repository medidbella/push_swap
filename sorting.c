/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:43:07 by midbella          #+#    #+#             */
/*   Updated: 2024/03/28 02:31:34 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (a->size == 3)
	{
		
	}
}

int	is_sorted(t_blk *blk, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (blk[i].num > blk[i + 1].num)
			return (0);
		i++;
	}
	return (1);
}

void	sorting(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		swap_stack(a, 1);
		exit(0);
	}
	if (a->size < 6)
		mini_sort(a, b);
}