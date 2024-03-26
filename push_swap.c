/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:40 by midbella          #+#    #+#             */
/*   Updated: 2024/03/26 02:22:56 by midbella         ###   ########.fr       */
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
			if (stk->arr[i] == stk->arr[iter] )
				error_handler(stk->arr);
			iter++;
		}
		start++;
	}
}

void error_handler(void	*free_me)
{
	free(free_me);
	write(2, "Error\n", 8);
	exit(1);
}

void	initializer(t_stack *stk , char **strs, int nb)
{
	int	i;

	stk->arr = malloc(sizeof(long) * (nb));
	stk->size = nb;
	i = 0;
	while (i < nb)
	{
		if (my_strlen(strs[i]) > 12)
			error_handler(stk->arr);
		stk->arr[i] = my_atoi(strs[i], stk->arr);
		i++;
	}
	double_check(stk);
	i = 0;
	while (i < nb)
		free(strs[i++]);
	free(strs);
}

void print_stack(t_stack *stack)
{
	int i;
	i = 0;
	while (i <= stack->size - 1)
	{
		print_nb(stack->arr[i++]);
		write(1 , "\n", 1);
	}
	if (i == 0)
		printf("non\n");
}

void init_stack(t_stack *a, t_stack *b)
{
	int i;

	i = a->size - 1;
	b->arr = malloc(sizeof (int) * a->size);
}

int main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		g;
	char	**args;


	a.arr = NULL;
	b.size = 0;
	if (ac == 1)
		return (0);
	b.arr = NULL;
	args = my_split(av, ac - 1);
	int i = 0;
	g = counter(av, ac - 1);
	if (!number_checker(g - 1, args))
		error_handler(args);
	initializer(&a, args, counter(av, ac -1));
	init_stack(&a, &b);
	first_idea(&a, &b);
}
