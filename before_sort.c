/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:18:17 by midbella          #+#    #+#             */
/*   Updated: 2024/04/19 09:56:16 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest_hepler(t_blk *blk, int size, int *index)
{
	int	last_unranked;
	int	unranked_numbers;

	last_unranked = 0;
	unranked_numbers = 0;
	while (last_unranked < size)
	{
		if (blk[last_unranked].rank == -1)
		{
			unranked_numbers++;
			*index = last_unranked;
		}
		last_unranked++;
	}
	return (unranked_numbers);
}

int	get_smallest(t_blk *blk, int size)
{
	int	index;
	int	result_index;
	int	helper_index;
	int	not_ranked;

	not_ranked = get_smallest_hepler(blk, size, &index);
	if (not_ranked == 1)
		return (index);
	else if (not_ranked == 0)
		return (-1);
	helper_index = 1;
	result_index = 0;
	while (helper_index < size)
	{
		if ((blk[result_index].num > blk[helper_index].num
				|| blk[result_index].rank != -1)
			&& (blk[helper_index].rank == -1))
			result_index = helper_index;
		helper_index++;
	}
	return (result_index);
}

void	ranker(t_blk *blk, int size)
{
	int	index;
	int	smalest_index;
	int	current_rank;

	current_rank = 0;
	index = 0;
	while (index < size)
	{
		blk[index].rank = -1;
		index++;
	}
	while (1)
	{
		smalest_index = get_smallest(blk, size);
		if (smalest_index == -1)
			break ;
		blk[smalest_index].rank = current_rank;
		current_rank++;
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
	while (len >= 0)
		res[--len] = arg[--temp];
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
