/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:34:32 by midbella          #+#    #+#             */
/*   Updated: 2024/03/31 23:41:22 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		g;
	char	**args;

	if (ac == 1)
		return (0);
	args = my_split(av, ac - 1);
	g = counter(av, ac - 1);
	if (!number_checker(g - 1, args))
		error_handler(args, NULL);
	initializer(&a, args, g);
	if (g == 1 || is_sorted(a.tab, a.size))
		return (0);
	ranker(a.tab, a.size);
	b.tab = malloc(sizeof(t_blk) * a.size);
	b.size = 0;
	sorting(&a, &b);
}
