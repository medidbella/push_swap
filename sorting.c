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
	exit(0);
}

void mini_sort(t_stack *a)
{
	if (a->size == 3)
		micro_sort(a);
	if (a->size == 2)
	{
		swap_stack(a, 1);
		exit(0);
	}
	return ;
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
		{
			write(1, "\n", 1);
			ft_putnbr(stk->tab[0].num);
			write(1, "\n", 1);
			rev_r_stack(stk, who);
			write(1, "\n", 1);
			ft_putnbr(tmp);
		}
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
	printf( "________________\n");
	while (i < stack->size)
	{
		printf("tab[%d] = %d\n", i, stack->tab[i].num);
		i++;
	}
	printf( "________________\n");
}

int	best_choice(t_stack *stk, int rang)
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = stk->size;
	while (1)
	{
		if (stk->tab[index1].rank <= rang)
			return (index1);
		else if (stk->tab[index2].rank <= rang)
			return (index2);
		index1++;
		index2--;
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
		rang = 30;
	if (a->size <= 5)
		return (mini_sort(a));
	while (a->size > 0)
	{
		ft_putnbr(best_choice(a, rang + def));
		cheap_push(a, b, best_choice(a, rang + def), def);
		def++;
	}
	while (b->size)
		cheap_push(b, a, find_bigest(b), -1);
}
