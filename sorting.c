/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:43:07 by midbella          #+#    #+#             */
/*   Updated: 2024/04/19 20:40:39 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bigest(t_stack *stk)
{
	int	result;
	int	i;

	i = 1;
	result = 0;
	while (i < stk->size)
	{
		if (stk->tab[result].num < stk->tab[i].num)
			result = i;
		i++;
	}
	return (result);
}

int	cheap_push(t_stack *src_stack, t_stack *dst_stack, int index, int def)
{
	int	which;
	int	tmp;

	if (def == -1)
		which = 2;
	else
		which = 1;
	tmp = src_stack->tab[index].num;
	if (src_stack->size / 2 > index)
		while (src_stack->tab[0].num != tmp)
			r_stack(src_stack, which);
	else
	{
		while (src_stack->tab[0].num != tmp)
			rev_r_stack(src_stack, which);
	}
	p_stack(src_stack, dst_stack, which);
	if (which == 1)
	{
		if (dst_stack->tab[0].rank <= def)
			r_stack(dst_stack, 2);
	}
	return (-1);
}

int	best_choice(t_stack *stk, int rang)
{
	int	index1;

	index1 = 0;
	while (1)
	{
		if (stk->tab[index1].rank <= rang)
			return (index1);
		index1++;
	}
	return (0);
}

void	sorting(t_stack *a, t_stack *b)
{
	int	rang;
	int	def;

	def = 0;
	if (a->size <= 6)
		return (mini_sort(a, b));
	if (a->size <= 100)
		rang = 15;
	else
		rang = 30;
	while (a->size > 0)
	{
		cheap_push(a, b, best_choice(a, rang + def), def);
		def++;
	}
	while (b->size)
		cheap_push(b, a, find_bigest(b), -1);
	free(a->tab);
	free(b->tab);
}
