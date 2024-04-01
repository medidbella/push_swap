/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:27:53 by midbella          #+#    #+#             */
/*   Updated: 2024/04/01 23:55:49 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counter(char **args, int nb)
{
	int	count;
	int	i;
	int	j;

	j = 1;
	count = 0;
	while (j <= nb)
	{
		i = 0;
		if (!is_what(args[j][0], 1))
			count++;
		while (args[j][i])
		{
			if (!is_what(args[j][i], 1) && is_what(args[j][i - 1], 1))
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

void	micro_sort(t_stack *a)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (i++ <= 2)
		if (a->tab[i].num > a->tab[i - 1].num)
			g = i;
	printf("\n%d\n", g);
	if (g == 0)
	{
		rev_r_stack(a, 1);
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

void	mini_sort(t_stack *a)
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
