/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:43:10 by midbella          #+#    #+#             */
/*   Updated: 2024/03/31 23:52:17 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	char	**args;
	int		j;

	if (ac == 1)
		return (0);
	args = my_split(av, ac - 1);
	j = counter(av, ac - 1);
	number_checker(j - 1, args);
	if (!number_checker(j - 1, args))
		error_handler(args, NULL);
	initializer(&a, args, j);
	b.tab = malloc(sizeof(t_blk) * a.size);
	b.size = 0;
}
