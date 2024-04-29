#include "push_swap.h"
#include <stdio.h>

static void push(t_node **dst, t_node **src);

//push a node to the top from src to dst (from stack a-> b OR from stack b -> a) - if stack is empty (NULL)?

/*

*/

static void	push(t_node **dst, t_node **src)
{
	t_node	*new_node;
	if (!*src)
		return ;
	new_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new_node->prev = NULL;
	if (!*dst)
	{
		*dst = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dst;
		new_node->next->prev = new_node;
		*dst = new_node;
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

