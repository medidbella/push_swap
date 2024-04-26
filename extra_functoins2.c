/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:15:05 by midbella          #+#    #+#             */
/*   Updated: 2024/04/21 18:38:05 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

int	ft_strcmp(char *orig, char *comp)
{
	int	i;

	i = 0;
	if (ft_strlen(orig) != ft_strlen(comp))
		return (0);
	while (orig[i])
	{
		if (orig[i] != comp[i])
			return (0);
		i++;
	}
	return (1);
}

void	error_handler(char **strs, t_blk *free_me)
{
	int	i;

	i = 0;
	if (strs)
		while (strs[i])
			free(strs[i++]);
	free(strs);
	free(free_me);
	write(2, "Error\n", 7);
	exit(1);
}

void	checker(char **args, int index)
{
	if (args[index] == NULL)
		error_handler(args, NULL);
}

char	*mini_joiner(char *str, char add_me, t_blk *free_me, t_blk *me_too)
{
	int		index;
	char	*res;
	int		len;

	index = 0;
	len = ft_strlen(str);
	res = malloc(sizeof(char) * len + 2);
	if (!res)
	{
		free(free_me),
		error_handler(NULL, me_too);
	}
	res[len + 1] = 0;
	res[len] = add_me;
	if (!str)
		return (res);
	while (str[index])
	{
		res[index] = str[index];
		index++;
	}
	return (free(str), res);
}
