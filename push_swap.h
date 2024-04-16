/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:08:46 by midbella          #+#    #+#             */
/*   Updated: 2024/04/02 18:11:19 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define P_LIM 2147483647
# define N_LIM -2147483648

typedef struct s_blk
{
	int		num;
	int		rank;
}			t_blk;

typedef struct s_stack
{
	t_blk	*tab;
	int		size;
}			t_stack;

int			my_strlen(char *str);
int			my_atoi(char *str, t_blk *ptr);
int			total_len(int n);
void		error_handler(char **strs, t_blk *free_me);
void		swap_stack(t_stack *stk, int who);
void		p_stack(t_stack *from, t_stack *to, int who);
void		r_stack(t_stack *stk, int who);
void		rev_r_stack(t_stack *stk, int who);
void		print_stack(t_stack *stack);
char		**my_split(char **args, int nb);
int			number_checker(int nb, char **strs);
int			is_what(char c, int wich);
int			counter(char **args, int nb);
void		ranker(t_blk *blk, int size);
int			is_sorted(t_blk *blk, int size);
void		sorting(t_stack *a, t_stack *b);
void		ft_putnbr(int n);
void		initializer(t_stack *stk, char **strs, int nb);
void		double_check(t_stack *stk);
void		mini_sort(t_stack *a);
void		micro_sort(t_stack *a);
void		free_args(char **args, int size);
int			find_bigest(t_stack *stk);

#endif