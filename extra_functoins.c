/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:49:44 by midbella          #+#    #+#             */
/*   Updated: 2024/04/18 18:51:18 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	what_is_it(char c, int wich)
{
	if (wich == 1)
		return (c == 32 || (c >= 9 && c <= 13));
	else if (wich == 0)
		return (c == '+' || c == '-');
	else if (wich == 2)
		return (c <= '9' && c >= '0');
	else
		return ((c == '+' || c == '-') || (c <= '9' && c >= '0'));
}

int	total_len(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		n = n * -1;
	}
	if (n < 10 && n >= 0)
		return (i);
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	my_atoi(char *str, t_blk *ptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (what_is_it(str[i], 0))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	if (result > P_LIM || result < N_LIM)
		error_handler(NULL, ptr);
	return ((int)result);
}

int	my_strlen(char *str)
{
	int	index;
	int	real_len;

	real_len = 0;
	index = 0;
	while (str[index] == '0' || what_is_it(str[index], 0))
		index++;
	while (str[index])
	{
		real_len++;
		index++;
	}
	return (real_len);
}

int	counter(char **args, int argument_number)
{
	int	count;
	int	iter;
	int	index;

	index = 1;
	count = 0;
	while (index <= argument_number)
	{
		iter = 0;
		if (!what_is_it(args[index][0], 1))
			count++;
		while (args[index][iter])
		{
			if (!what_is_it(args[index][iter], 1) &&
				what_is_it(args[index][iter - 1], 1) && index)
				count++;
			iter++;
		}
		index++;
	}
	return (count);
}
