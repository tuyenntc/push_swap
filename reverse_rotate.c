#include "push_swap.h"

//reverse rotate: rotate the bottom node to the top position

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
/*
void	reverse_rotate(t_node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;
	t_node	*last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = (*head);
	(*head)->prev = last;
	last->prev->next = NULL;
	*head = last;
}
*/
void	rra(t_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}


void	rrr(t_node **a, t_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
