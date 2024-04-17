/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:43:10 by midbella          #+#    #+#             */
/*   Updated: 2024/04/17 19:27:34 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_operatoin_id(char	*my_operatoin)
{
	int		index;
	char	*operatoins[11];

	if (!my_operatoin)
		return (11);
	index = 0;
	operatoins[0] = "sa\n";
	operatoins[1] = "sb\n";
	operatoins[2] = "pa\n";
	operatoins[3] = "ss\n";
	operatoins[4] = "pb\n";
	operatoins[5] = "ra\n";
	operatoins[6] = "rb\n";
	operatoins[7] = "rr\n";
	operatoins[8] = "rra\n";
	operatoins[9] = "rrb\n";
	operatoins[10] = "rrr\n";
	while (index <= 10)
	{
		if (ft_strcmp(operatoins[index], my_operatoin))
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_get_operatoin(t_blk *free_me, t_blk *me_to, int *state)
{
	int		guarder;
	char	buf[1];
	char	*res;

	res = NULL;
	buf[0] = 0;
	while (buf[0] != '\n')
	{
		guarder = read(0, buf, 1);
		if (guarder != 1)
			break ;
		res = mini_joiner(res, buf[0]);
	}
	if (guarder == -1)
	{
		free(free_me);
		error_handler(NULL, me_to);
	}
	if (guarder == 0)
		*state = -1;
	return (res);
}

void	do_operatoin(t_stack *a, t_stack *b, int id)
{
	if (id == 3)
	{
		swap_stack(a, 0);
		swap_stack(b, 0);
	}
	else if (id == 4)
		p_stack(a, b, 0);
	else if (id == 5)
		r_stack(a, 0);
	else if (id == 6)
		r_stack(b, 0);
	else if (id == 7)
	{
		r_stack(a, 0);
		r_stack(b, 0);
	}
	else if (id == 8)
		rev_r_stack(a, 0);
	else if (id == 9)
		rev_r_stack(b, 0);
	else if (id == 10)
	{
		rev_r_stack(b, 0);
		rev_r_stack(a, 0);
	}
}

void	read_and_applicate(t_stack *a, t_stack *b)
{
	char	*my_operatoin;
	int		state;
	int		operatoin_id;

	state = 1;
	my_operatoin = NULL;
	while (state != -1)
	{
		free(my_operatoin);
		my_operatoin = ft_get_operatoin(a->tab, b->tab, &state);
		operatoin_id = get_operatoin_id(my_operatoin);
		if (operatoin_id == -1)
		{
			free(my_operatoin);
			free(b->tab);
			error_handler(NULL, a->tab);
		}
		if (operatoin_id == 0)
			swap_stack(a, 0);
		else if (operatoin_id == 1)
			swap_stack(b, 0);
		else if (operatoin_id == 2)
			p_stack(b, a, 0);
		do_operatoin(a, b, operatoin_id);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		arg_number;

	if (ac == 1)
		return (0);
	arg_number = counter(av, ac - 1);
	args = my_split(av, ac - 1, arg_number);
	number_checker(args);
	if (!number_checker(args))
		error_handler(args, NULL);
	initializer(&a, args, arg_number);
	b.tab = malloc(sizeof(t_blk) * a.size);
	if (!b.tab)
		error_handler(NULL, a.tab);
	b.size = 0;
	read_and_applicate(&a, &b);
	if (b.size == 0 && is_sorted(a.tab, a.size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
