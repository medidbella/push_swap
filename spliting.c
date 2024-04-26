/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:18:17 by midbella          #+#    #+#             */
/*   Updated: 2024/04/25 16:14:46 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void result_filler(char *src, char *dst, int src_index, int dst_index)
{
	--src_index;
	--dst_index;
	while (dst_index >= 0)
	{
		dst[dst_index] = src[src_index];
		dst_index--;
		src_index--;
	}
}

char	*split_and_fill(char *arg, int *ptr)
{
	char		*res;
	static int	static_index;
	int			len;
	int			temp;

	if (*ptr == -1)
		static_index = 0;
	len = 0;
	while (what_is_it(arg[static_index], 1))
		static_index++;
	while (!what_is_it(arg[static_index], 1) && arg[static_index])
	{
		static_index++;
		len++;
	}
	temp = static_index;
	*ptr = static_index;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	result_filler(arg, res, temp, len);
	return (res);
}

char	**my_split(char **args, int nb, int av_index)
{
	int		res_index;
	char	**res;
	int		iter;

	res_index = 0;
	iter = 0;
	res = malloc(sizeof(char *) * (av_index + 1));
	if (!res)
		error_handler(NULL, NULL);
	res[av_index] = NULL;
	av_index = 1;
	while (av_index <= nb)
	{
		res[res_index] = split_and_fill(args[av_index], &iter);
		checker(res, res_index);
		while (what_is_it(args[av_index][iter], 1))
			iter++;
		if (args[av_index][iter] == '\0')
		{
			iter = -1;
			av_index++;
		}
		res_index++;
	}
	return (res);
}
