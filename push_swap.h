/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midbella <midbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:08:46 by midbella          #+#    #+#             */
/*   Updated: 2024/03/26 02:23:07 by midbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# define P_LIM 2147483647
# define N_LIM -2147483648
 
typedef struct s_stack
{
	int *arr;
	int size;
} t_stack;

int		print_nb(int nb);
int		my_strlen(char *str);
int		my_atoi(char *str, int *ptr);
int		total_len(int n);
void	error_handler(void	*free_me);
char	*ft_strdup(char *s1);
void	swap_stack(t_stack *stk);
void	p_stack(t_stack *from, t_stack *to);
void	r_stack(t_stack *stk);
void	rev_r_stack(t_stack *stk);
void	first_idea(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
char	**my_split(char **args, int nb);
int		number_checker(int nb, char **strs);
int		is_what(char c, int wich);
int		counter(char **args, int nb);

#endif