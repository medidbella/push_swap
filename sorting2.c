/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:27:53 by midbella          #+#    #+#             */
/*   Updated: 2024/04/17 19:25:55 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smalest(t_stack *stk)
{
	int	result;
	int	i;

	i = 1;
	result = 0;
	while (i < stk->size)
	{
		if (stk->tab[result].num > stk->tab[i].num)
			result = i;
		i++;
	}
	return (result);
}

void	micro_sort(t_stack *a)
{
	int	g;

	if (a->size == 2)
	{
		swap_stack(a, 1);
		return ;
	}
	g = find_bigest(a);
	if (g == 0)
		r_stack(a, 1);
	else if (g == 1)
		rev_r_stack(a, 1);
	if (a->tab[0].num > a->tab[1].num)
		swap_stack(a, 1);
	return ;
}

void	mini_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
	{
		micro_sort(a);
		free(a->tab);
		free(b->tab);
		exit(0);
	}
	while (a->size != 3)
		cheap_push(a, b, find_smalest(a), -37);
	micro_sort(a);
	if (b->tab[0].num < b->tab[1].num)
		swap_stack(b, 2);
	while (b->size)
		p_stack(b, a, 2);
	free(a->tab);
	free(b->tab);
}
