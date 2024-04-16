/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:43:07 by midbella          #+#    #+#             */
/*   Updated: 2024/04/16 09:38:11 by midbella         ###   ########.fr       */
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

int	cheap_push(t_stack *stk, t_stack *stk1, int index, int def)
{
	int	who;
	int	tmp;

	if (def == -1)
		who = 2;
	else
		who = 1;
	tmp = stk->tab[index].num;
	if (stk->size / 2 > index)
		while (stk->tab[0].num != tmp)
			r_stack(stk, who);
	else
	{
		while (stk->tab[0].num != tmp)
			rev_r_stack(stk, who);
	}
	p_stack(stk, stk1, who);
	if (who == 1)
	{
		if (stk1->tab[0].rank <= def)
			r_stack(stk1, 2);
	}
	return (-1);
}

int	best_choice(t_stack *stk, int rang)
{
	int	index1;
	int	index2;

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
	if (a->size <= 100)
		rang = 15;
	else
		rang = 25;
	if (a->size <= 5)
		return (mini_sort(a));
	while (a->size > 0)
	{
		cheap_push(a, b, best_choice(a, rang + def), def);
		def++;
	}
	while (b->size)
		cheap_push(b, a, find_bigest(b), -1);
}
