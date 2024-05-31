#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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
	// int			count_move;
	// int			cheaper;
	// int			higher;
	// int			minor;
	struct s_stack	*next;
}					t_stack;


// void ft_display(t_list *n)
// {
// 	while(n != NULL)
// 	{
// 		printf("%d , ", *(int *)n->content);
// 		 n = n->next;
// 	}
// }
// int main()
// {
// 	t_list *head = NULL;
// 	int a = 1337;
// 	void *pta = &a;
// 	t_list *node1 = ft_lstnew(pta);

// 	head = node1;
// 	int b = 42;
// 	void *ptb = &b;
// 	t_list *node2 = ft_lstnew(ptb);

// 	ft_lstadd_front(&head, node2);  // Pass the address of head to modify it

// 	int c = 50;
// 	void *ptc = &c;
// 	t_list *node3 = ft_lstnew(ptc);

// 	ft_lstadd_front(&head, node3); 

// 	printf("Contents of the list:\n");
// 	ft_display(head);

// 	free(node1);
// 	free(node2);
// 	free(node3);
// 	return 0;
// }

// ORDENAMIENTO

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

//void push (t_stack a, t_stack b )
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




// void push_other_stack(t_stack **before, int content, int pos)
// {
// 	 t_stack *new;

// 	if (!before)
// 		return;

// 	new = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new)
// 		return;
	
// 	new->content = content;
// 	new->index = 0;
// 	new->pos = pos;
// 	new->count_move = -1;
// 	new->cheaper = -1;
// 	new->higher = -1;
// 	new->minor = -1;
// 	new->next = *before;
// 	*before = new;
// }


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



				// node 1 			node 2
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
	// new->count_move = -1;
	// new->cheaper = -1;
	// new->higher = -1;
	// new->minor = -1;
	new->next = *before;
	*before = new;
}


// ft_replace(argv)
// {

// }

//void ft_swap()
//void push
// voud rotate
// void reverse
//void rrr
// int	ft_doble_char(char *str)
// {
// 	int i;
// 	int	j;
	
// 	i = 0;
// 	while(i < strlen(str))
// 	{
// 		j = i + 1;
// 		while(j < strlen(str))
// 		{
// 		  	if(str[i] == str[j])
// 				return (1);
// 		  	j++;
// 		}
// 		i++;
// 	  }
// 	return (0);
// }

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
void ft_display(t_stack *n)
{
	int count = 0;
	while(n != NULL)
	{
		printf(" | contenido: %d | ", n->content);
		printf(" index: %d | ", n->index);
		printf(" pos: %d | ", n->pos);
		// printf(" count_move: %d | ", n->count_move);
		// printf(" cheaper: %d | ", n->cheaper);
		// printf(" higher: %d | ", n->higher);
		// printf(" minor: %d | ", n->minor);
		printf(" count: %d | \n", count++);
		 n = n->next;
	}
}
int main (int argc, char **argv)
{
	 t_stack *head = NULL; 
	 int i = argc;
	
	// int a = 50;
	// int b = 40;
	// int c = 30;
	// int d = 10;
	// int e = 20;
	// ft_push(&head,a);
	// ft_push(&head,b);
	// ft_push(&head,c);
	// ft_push(&head,d);
	// ft_push(&head,e);
	// ft_display(head);
	// free(head);
	//ft_replace(argv);
	if (argc >= 2)
	{
		while (--i > 0)
		{
			ft_push(&head,ft_atoi(argv[i]),i);
		}

		printf("%d\n", ft_check(head));
		ft_sort_index(head);
		ft_rotate(&head);
		//ft_rotate_reverse(&head);
		///ft_swap(&head);
	//	ft_swap(&head);
		ft_display(head);
		free(head);
	}
}


///void ft_printf()
// int main ()
// {
// 	struct t_list *head = NULL;

// 	int a = 1337;
// 	int b = 80;
// 	int c = 80;

// 	void *pa = &a;
// 	void *pb = &b;
// 	void *pc = &c;

// 	t_list * node1 = ft_lstadd(pa);
// 	head = node1;

// 	t_list *node2 = ft_lstnew(pb);
// 	ft_lstadd_front(&head, node2);

// 	t_list *node3 = ft_lstnew(pc);
// 	ft_lstadd_front(&head, node3);

// 	ft_display(head);

// 	return 0;
// }

