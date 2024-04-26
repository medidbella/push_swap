/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mondatory_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:34:32 by midbella          #+#    #+#             */
/*   Updated: 2024/04/26 09:15:10 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		arg_number;
	char	**args;

	if (ac == 1)
		return (0);
	arg_number = counter(av, ac - 1);
	args = my_split(av, ac - 1, arg_number);
	if (!number_checker(args))
		error_handler(args, NULL);
	initializer(&a, args, arg_number);
	if (arg_number == 1 || is_sorted(a.tab, a.size))
		return (free(a.tab), 0);
	ranker(a.tab, a.size);
	b.tab = malloc(sizeof(t_blk) * a.size);
	if (!b.tab)
		error_handler(NULL, a.tab);
	b.size = 0;
	sorting(&a, &b);
	return (0);
}
