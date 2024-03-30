/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:49:44 by midbella          #+#    #+#             */
/*   Updated: 2024/03/30 19:50:58 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_what(char c, int wich)
{
	if (wich == 1)
		return (c == 32 || (c >= 9 && c <= 13));
	else if (wich == 0)
		return (c == '+' || c == '-');
	else if (wich == 2)
		return (c <= '9' && c >= '0');
	else
		return ((c == '+' || c == '-')
			|| (c <= '9' && c >= '0'));
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
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (is_what(str[i], 0))
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
	if (result >= P_LIM || result <= N_LIM)
		error_handler(ptr);
	return ((int)result);
}

int	my_strlen(char *str)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	while (str[i] == '0' || is_what(str[i], 0))
		i++;
	while (str[i])
	{
		o++;
		i++;
	}
	return (o);
}

//del from here
void	ft_putnbr(int n)
{
	long	nb;
	char	s[10];
	int		j;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
			nb = nb * -1;
	}
	j = 0;
	while (nb >= 10)
	{
		s[j] = (nb % 10) + 48;
		nb = nb / 10;
		j++;
	}
	s[j] = nb + 48;
	while (j >= 0)
	{
		write(1, &s[j], 1);
		j--;
	}
}