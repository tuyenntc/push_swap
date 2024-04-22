#include "push_swap.h"

//push a node to the top from src to dst (from stack a-> b OR from stack b -> a) - if stack is empty (NULL)?

static void	push(t_node **dst, t_node **src)
{
	t_node	*node_to_push;
	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dst == NULL)
	{
		*dst = node_to_push;
		node_to_push->next = NULL:
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_node **a, t_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}

