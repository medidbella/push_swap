/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:43:10 by midbella          #+#    #+#             */
/*   Updated: 2024/04/02 21:54:09 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_and_parse(void)
{
	char	**result;
	char	*res;
	char	buf[2];
	int		r;

	buf[1] = 0;
	res = NULL;
	r = read(0, buf, 1);
	if (r == -1)
		
	while (r > 0)
	{
		
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	char	*operatoins;
	int		j;

	if (ac == 1)
		return (0);
	args = my_split(av, ac - 1);
	j = counter(av, ac - 1);
	number_checker(j - 1, args);
	if (!number_checker(j - 1, args))
		delete(args, NULL, 0);
	initializer(&a, args, j);
	b.tab = malloc(sizeof(t_blk) * a.size);
	b.size = 0;
	operatoins = read_and_parse();
}
