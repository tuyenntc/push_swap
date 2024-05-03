#include "push_swap.h"

//rotate the top node to the bottom position

static void	rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}
/*
void	rotate(t_node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return;
	t_node	*last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	(*head)->prev = last;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->next = NULL;
}



*/
void	ra(t_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
