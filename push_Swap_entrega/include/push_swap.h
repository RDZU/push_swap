/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:18:42 by razamora          #+#    #+#             */
/*   Updated: 2024/06/30 20:19:43 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				pos_init;
	struct s_stack	*next;
}					t_stack;

int		count_r(t_stack *stack, int index);
void	ksort_part_one(t_stack **stack_a, t_stack **stack_b, int length);
void	ksort_part_two(t_stack **stack_a, t_stack **stack_b, int length);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_reverse(t_stack **list, char type);
void	ft_rotate(t_stack **list, char type);
void	ft_rotate_double(t_stack **stack_a, t_stack **stack_b);
void	push_other_stack(t_stack **a, t_stack **b, char type);
void	ft_swap(t_stack **list, char type);
int		ft_atoi_check(const char *str);
void	ft_push(t_stack **before, int content, int pos);
void	ft_check_equal( t_stack *head);
void	ft_sort_index(t_stack *head);
void	ft_is_numeric(const char *str);
void	ft_is_ordened(t_stack *head);
void	ft_msm_error(char *str, int flag);
void	ft_free_argv(char **mat);
size_t	ft_count_arg(char const *s, char c);
void	ft_check_empty(char const *s);
int		ft_sqrt(int number);
int		*process_argv(int argc, char **argv, t_stack **stack_a, char **words);
int		ft_calculate_number_elem(int argc, char **argv);
int		ft_check_string(const char *str);
void	ft_check_range(long number);
int		ft_size_list(t_stack *head);
t_stack	*ft_lst_last(t_stack *lst);
void	ft_lst_clear(t_stack **lst);

#endif