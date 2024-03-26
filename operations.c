/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:10:43 by midbella          #+#    #+#             */
/*   Updated: 2024/03/25 17:24:22 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stk)
{
	int	tmp;

	if (stk->size <= 1)
		return ;
	tmp = stk->arr[0];
	stk->arr[0] = stk->arr[1];
	stk->arr[1] = tmp;
}

void	expand_stack(t_stack *stk)
{
	int	i;

	i = stk->size;
	while (i != 0)
	{
		stk->arr[i] = stk->arr[i - 1];
		i--;
	}
}

void	p_stack(t_stack *from, t_stack *to)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = from->arr[0];
	while (i < from->size - 1)
	{
		from->arr[i] = from->arr[i + 1];
		i++;
	}
	from->size--;
	to->size++;
	expand_stack(to);
	to->arr[0] = tmp;
}

void	r_stack(t_stack *stk)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stk->arr[0];
	while (i < stk->size - 1)
	{
		stk->arr[i] = stk->arr[i + 1];
		i++;
	}
	stk->arr[stk->size - 1] = tmp;
}

void	rev_r_stack(t_stack *stk)
{
	int	tmp;
	int	i;

	tmp = stk->arr[stk->size - 1];
	i = stk->size - 1;
	while (i > 0)
	{
		stk->arr[i] = stk->arr[i - 1];
		i--;
	}
	stk->arr[0] = tmp;
}
