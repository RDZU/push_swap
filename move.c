/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:52:12 by razamora          #+#    #+#             */
/*   Updated: 2024/06/22 23:52:35 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_swap(t_stack **list, char type)
{
	t_stack	*aux;

	if (!list || !(*list)->next)
		return ;
	aux = *list;
	*list = (*list)->next;
	aux->next = (*list)->next;
	(*list)->next = aux;
	if (type == 97)
		write(1, "sa\n", 3);
	if (type == 98)
		write(1, "sb\n", 3);
}

void	ft_rotate(t_stack **list, char type)
{
	t_stack		*last;
	t_stack		*first;

	if (!list || !*list || ft_size_list(*list) < 2)
		return ;

	first = (*list);
	last = ft_lstlast(*list);
	*list = (*list)->next;
	last->next = first;
	first->next = NULL;
	if (type == 97)
		write(1, "ra\n", 3);
	if (type == 98)
		write(1, "rb\n", 3);
}

void	ft_rotate_reverse(t_stack **list, char type)
{
	t_stack		*first;
	t_stack		*aux;
	t_stack		*last;

	if (!list || !(*list)->next)
		return ;
	first = (*list);
	last = ft_lstlast(*list);
	aux = *list;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	last->next = first;
	*list = last;
	if (type == 97)
		write(1, "rra\n", 4);
	if (type == 98)
		write(1, "rrb\n", 4);
}

void	push_other_stack(t_stack **a, t_stack **b, char type)
{
	t_stack	*aux;
	t_stack	*new;
	int		content;
	int		index;
	int		pos;

	if ((*a))
	{
		if (!a || !b)
			return ;
		aux = *a;
		(*a) = (*a)->next;
		aux->next = *b;
		(*b) = aux;
		if (type == 97)
			write(1, "pa\n", 3);
		if (type == 98)
			write(1, "pb\n", 3);
	}
	ft_display(*a);
	ft_display(*b);
}
