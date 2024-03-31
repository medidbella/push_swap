/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:43:07 by midbella          #+#    #+#             */
/*   Updated: 2024/03/31 21:41:23 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void mini_sort(t_stack *a)
{
	if (a->size == 2)
	{
		swap_stack(a, 1);
		exit(0);
	}
	return ;
}

void	micro_sort(t_stack *a)
{
	int i;
	int g;

	i = 0;
	g = 0;
	while (i++ <= 2)
		if (a->tab[i].num > a->tab[i - 1].num)
			g = i;
	if (g == 0)
	{
		r_stack(a, 1);
		if (a->tab[0].num > a->tab[1].num)
			swap_stack(a, 1);
		return ;
	}
	else if (g == 1)
	{
		rev_r_stack(a, 1);
		if (a->tab[0].num > a->tab[1].num)
			swap_stack(a, 1);
		return ;
	}
	if (a->tab[0].num > a->tab[1].num)
		swap_stack(a, 1);
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

int	find_bigest(t_stack *stk)
{
	int result;
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
	int who;
	int tmp;

	if (def == -1)
		who = 2;
	else
		who = 1;
	tmp = stk->tab[index].num;
	if (stk->size / 2 > index)
		while (stk->tab[0].num != tmp)
			r_stack(stk, who);
	else
		while (stk->tab[0].num != tmp)
			rev_r_stack(stk, who);
	p_stack(stk, stk1, who);
	if (who == 1)
	{
		if (stk1->tab[0].rank <= def)
			swap_stack(stk1, 2);
	}
	return (-1);
}

void print_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		printf("tab[%d] = %d\n", i, stack->tab[i].num);
		i++;
	}
}

void	sorting(t_stack *a, t_stack *b)
{
	int	index;
	int	rang;
	int	def;

	def = 0;
	index = 0;
	if (a->size <= 100)
		rang = 15;
	else 
		rang = 30;
	if (a->size == 3)
		return (micro_sort(a));
	else if (a->size <= 5)
		return (mini_sort(a));
	while (a->size != 0)
	{
		if (a->tab[index].rank <= (rang + def))
		{
			index = cheap_push(a, b, index, def);
			def++;
		}
		index++;
	}
	while (b->size)
		cheap_push(b, a, find_bigest(b), -1);
}
