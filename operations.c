/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:10:43 by midbella          #+#    #+#             */
/*   Updated: 2024/03/30 18:34:00 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stk, int who)
{
	t_blk	tmp;

	if (stk->size <= 1)
		return ;
	tmp = stk->tab[0];
	stk->tab[0] = stk->tab[1];
	stk->tab[1] = tmp;
	if (who == 1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	expand_stack(t_stack *stk)
{
	int	i;

	i = stk->size;
	while (i != 0)
	{
		stk->tab[i] = stk->tab[i - 1];
		i--;
	}
}

void	p_stack(t_stack *from, t_stack *to, int who)
{
	int		i;
	t_blk	tmp;

	i = 0;
	tmp = from->tab[0];
	while (i < from->size - 1)
	{
		from->tab[i] = from->tab[i + 1];
		i++;
	}
	from->size--;
	to->size++;
	expand_stack(to);
	to->tab[0] = tmp;
	if (who == 2)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	r_stack(t_stack *stk, int who)
{
	t_blk	tmp;
	int	i;

	if (stk->size == 0)
		return ;
	i = 0;
	tmp = stk->tab[0];
	while (i < stk->size - 1)
	{
		stk->tab[i] = stk->tab[i + 1];
		i++;
	}
	stk->tab[stk->size - 1] = tmp;
	if (who == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rev_r_stack(t_stack *stk, int who)
{
	t_blk	tmp;
	int	i;

	if (stk->size == 0)
		return ;
	tmp = stk->tab[stk->size - 1];
	i = stk->size - 1;
	while (i > 0)
	{
		stk->tab[i] = stk->tab[i - 1];
		i--;
	}
	stk->tab[0] = tmp;
	if (who == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
