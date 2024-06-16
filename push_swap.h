/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razamora <razamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:18:42 by razamora          #+#    #+#             */
/*   Updated: 2024/06/16 13:09:18 by razamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct	s_stack
{
	int				content;
	int				index;
	int				pos;
	struct s_stack	*next;
}					t_stack;

//void	ft_sort(t_stack *a, t_stack *b, int size_list);
//void	ft_swap(t_stack **list);

#endif