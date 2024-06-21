/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:18:42 by razamora          #+#    #+#             */
/*   Updated: 2024/06/17 20:25:08 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_stack
{
	int				content;
	int				index;
	int				pos;
	struct s_stack	*next;
}					t_stack;

int		ft_lstsize(t_stack *lst);
//int	ft_lstsize(t_stack *lst);
int		count_r(t_stack *stack, int index);
void	ksort_part_one(t_stack **stack_a, t_stack **stack_b, int length);
void	ksort_part_two(t_stack **stack_a, t_stack **stack_b, int length);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
int		ft_atoi(const char *str);
int		ft_size_list(t_stack *head);
void	ft_push(t_stack **before, int content, int pos);
void	ft_check_equal( t_stack *head);
int		ft_is_sort(t_stack *head);
void	ft_sort_index(t_stack *head);
void	ft_display(t_stack *n);
void	ft_rotate_reverse(t_stack **list, char type);
void	ft_rotate(t_stack **list, char type);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	push_other_stack(t_stack **a, t_stack **b, char type);
void	ft_swap(t_stack **list, char type);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
//void	ft_is_numeric(char *str);
void	ft_is_numeric(const char *str);
void	ft_is_ordened(t_stack *head);
void	ft_msm_error(char *str, int flag);
size_t	ft_strlen(const char *s);
char **ft_split(char *str, char delimiter);

#endif