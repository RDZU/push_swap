#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int				content;
	int				index;
	int				pos;

	struct s_stack	*next;
}					t_stack;


t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_is_sort(t_stack *head)
{
	t_stack *i;
	t_stack *j;

	i = head;
	while (i != NULL)
	{
		j = i->next;
		while(j != NULL && j->next != NULL)
		{
			if (i->content > j->content)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return(1);
}


void ft_push(t_stack **before, int content, int pos) {
    t_stack *new;

	if (!before)
		return;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return;
	
	new->content = content;
	new->index = 0;
	new->pos = pos;
	new->next = *before;
	*before = new;
}

void	ft_rotate_reverse(t_stack **list)
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
	write(1,"rra\n",4);
}

void ft_rotate(t_stack **list)
{
	t_stack		*last;
	t_stack		*first;
	
	if (!list || !*list)
		return ;
	first = (*list);
	last = ft_lstlast(*list);
	*list = (*list)->next;
    last->next = first;
    first->next = NULL;
	write(1,"ra\n",3);
}

void ft_swap(t_stack **list)
{
	t_stack *aux;

	if (!list || !(*list)->next)
		return ;

	aux = *list;
	*list = (*list)->next;
	aux->next = (*list)->next;
	(*list)->next = aux;
}

void ft_display(t_stack *n)
{
	int count = 0;
	while(n != NULL)
	{
		printf(" | contenido: %d | ", n->content);
		printf(" index: %d | ", n->index);
		printf(" pos: %d | ", n->pos);
		printf(" count: %d | \n", count++);
		 n = n->next;
	}
}
int main (int argc, char **argv)
{
	 t_stack *head = NULL; 
	 

	 int a = 10;
	 int b = 20;
	 int c = 30;
	
	ft_push(&head,a,1);
	ft_push(&head,b,2);
	ft_push(&head,c,3);
	//ft_sort_index(head);
    ft_rotate(&head);
	ft_display(head);
	free(head);
}

int ft_check( t_stack *head)
{
	t_stack	*i;
	t_stack	*j;

	i = head;
	
	while (i != NULL)
	{
		j = i->next;
		while(j != NULL)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return 0;
}


void ft_sort_index(t_stack *head)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	index = 0;

	i = head;
	
	while (i != NULL)
	{
		j = i->next;
		while(j != NULL)
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

int ft_size_list(t_stack *head)
{
	int pos;
	if (!head)
		return (0);

	while (head != NULL)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
