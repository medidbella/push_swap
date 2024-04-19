/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:10:43 by midbella          #+#    #+#             */
/*   Updated: 2024/04/19 10:46:49 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stk, int which)
{
	t_blk	tmp;

	if (stk->size <= 1)
		return ;
	tmp = stk->tab[0];
	stk->tab[0] = stk->tab[1];
	stk->tab[1] = tmp;
	if (which == 1)
		write(1, "sa\n", 3);
	else if (which == 2)
		write(1, "sb\n", 3);
}

void	expand_stack(t_stack *stk)
{
	int	i;

	if (stk->size == 0)
		return ;
	i = stk->size;
	while (i != 0)
	{
		stk->tab[i] = stk->tab[i - 1];
		i--;
	}
}

void	p_stack(t_stack *from, t_stack *to, int which)
{
	int		i;
	t_blk	tmp;

	i = 0;
	if (from->size == 0)
		return ;
	tmp = from->tab[0];
	while (i < from->size - 1)
	{
		from->tab[i] = from->tab[i + 1];
		i++;
	}
	from->size--;
	expand_stack(to);
	to->tab[0] = tmp;
	to->size++;
	if (which == 1)
		write(1, "pb\n", 3);
	else if (which == 2)
		write(1, "pa\n", 3);
}

void	r_stack(t_stack *stk, int which)
{
	t_blk	tmp;
	int		i;

	i = 0;
	tmp = stk->tab[0];
	while (i < stk->size - 1)
	{
		stk->tab[i] = stk->tab[i + 1];
		i++;
	}
	stk->tab[stk->size - 1] = tmp;
	if (which == 1)
		write(1, "ra\n", 3);
	else if (which == 2)
		write(1, "rb\n", 3);
}

void	rev_r_stack(t_stack *stk, int which)
{
	t_blk	tmp;
	int		i;

	tmp = stk->tab[stk->size - 1];
	i = stk->size - 1;
	while (i > 0)
	{
		stk->tab[i] = stk->tab[i - 1];
		i--;
	}
	stk->tab[0] = tmp;
	if (which == 1)
		write(1, "rra\n", 4);
	else if (which == 2)
		write(1, "rrb\n", 4);
}
