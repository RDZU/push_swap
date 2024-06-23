/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:00:58 by razamora          #+#    #+#             */
/*   Updated: 2024/06/23 01:33:44 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_push(t_stack **before, int content, int pos)
{
	t_stack	*new;

	if (!before)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = content;
	new->index = 0;
	new->pos = pos;
	new->next = *before;
	*before = new;
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*aux;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		free(aux);
	}
	*lst = NULL;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_size_list(t_stack *head)
{
	int	pos;

	if (!head)
		return (0);
	pos = 0;
	while (head != NULL)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}

void	ft_sort_index(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	index = 0;
	i = head;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->content > j->content)
				i->index += 1;
			else if (i->content < j->content)
				j->index += 1;
			j = j->next;
		}
		i = i->next;
	}
}
