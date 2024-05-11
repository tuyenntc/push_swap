#include "push_swap.h"


static void	swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
/*
static void	swap(t_node **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return ;
	t_node	*first = *head;
	t_node	*second = first->next;

	first->next = second->next;
	first->prev = second;
	if (second->next != NULL)
		second->next = first;
	second->prev = NULL;
	first->next->prev = second->prev;
	*head = second;
}
*/
void	sa(t_node **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
