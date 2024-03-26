/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:43:07 by midbella          #+#    #+#             */
/*   Updated: 2024/03/20 01:49:32 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pull_up(t_stack *a, int index, int nb)
{
	if (a->size / 2 >= (index + 1))
		while (a->arr[0] != nb)
		{
			r_stack(a);
			printf("ra\n");
		}
	else 
		while (a->arr[0] != nb)
		{
			rev_r_stack(a);
			printf("rra\n");
		}
}

void	first_idea(t_stack *a, t_stack *b)
{
	int	s;
	int i;

	while (a->size != 0)
	{
		s = 0; 
		i = 1;
		while (i < a->size)
		{
			if (a->arr[i] < a->arr[s])
				s = i;
			i++;
		}
		pull_up(a, s, a->arr[s]);
		p_stack(a, b);
		printf("pb\n");
	}
	while (b->size != 0)
	{
		p_stack(b, a);
		printf("pa\n");
	}
}
