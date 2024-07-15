/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:28:54 by razamora          #+#    #+#             */
/*   Updated: 2024/03/27 19:14:10 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*aux;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		aux = current;
		current = current->next;
		del(aux->content);
		free(aux);
	}
	*lst = NULL;
}
