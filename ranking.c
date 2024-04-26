/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:41:25 by midbella          #+#    #+#             */
/*   Updated: 2024/04/25 15:42:22 by midbella         ###   ########.fr       */
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