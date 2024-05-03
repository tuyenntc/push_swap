#include "push_swap.h"
#include <stdio.h>

//push a node to the top from src to dst (from stack a-> b OR from stack b -> a) - if stack is empty (NULL)?

/*

*/

static void	push(t_node **dst, t_node **src)
{
	t_node	*new;
	if (!*src)
		return ;
	new = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new->prev = NULL;
	if (!*dst)
	{
		*dst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *dst;
		new->next->prev = new;
		*dst = new;
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

