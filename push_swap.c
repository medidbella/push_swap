/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:40 by midbella          #+#    #+#             */
/*   Updated: 2024/03/31 01:09:37 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	double_check(t_stack *stk)
{
	int start;
	int	i;
	int iter;

	start = 0;
	while (start < stk->size - 1)
	{
		i = start;
		iter = start + 1;
		while (iter <= stk->size - 1)
		{
			if (stk->tab[i].num == stk->tab[iter].num)
				error_handler(stk->tab);
			iter++;
		}
		start++;
	}
}

void error_handler(void	*free_me)
{
	free(free_me);
	write(2, "Error\n", 7);
	exit(1);
}

void	initializer(t_stack *stk , char **strs, int nb)
{
	int	i;

	stk->tab = malloc(sizeof(t_blk) * (nb));
	stk->size = nb;
	i = 0;
	while (i < nb)
	{
		stk->tab[i].rank = i;
		i++;
	}
	i = 0;
	while (i < nb)
	{
		if (my_strlen(strs[i]) > 12)
			error_handler(stk->tab);
		stk->tab[i].num = my_atoi(strs[i], stk->tab);
		i++;
	}
	double_check(stk);
	i = 0;
	while (i < nb)
		free(strs[i++]);
	free(strs);
}

int main(int ac, char **av)
{
	t_blk	*blk;
	t_stack	a;
	t_stack	b;
	int		g;
	char	**args;

	blk = NULL;
	a.tab = blk;
	if (ac == 1)
		return (0);
	args = my_split(av, ac - 1);
	g = counter(av, ac - 1);
	if (!number_checker(g - 1, args))
		error_handler(args);
	initializer(&a, args, g);
	if (g == 1 || is_sorted(a.tab, a.size))
		return (0);
	ranker(a.tab, a.size);
	b.tab = malloc(sizeof(t_blk) * a.size);
	b.size = 0;
	sorting(&a, &b);
}
