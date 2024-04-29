#include "push_swap.h"

//free the whole linked list
void	deallocate(t_node **head, t_node **tail)
{
	if (*head == NULL)
		return;
	t_node	*current = *head;
	while (current->next != NULL)
	{
		current = current->next;
		free(current->prev);
	}
	free(current);
	*head = NULL;
	*tail = NULL;
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_node **a)
{
	free_stack(a);
	write(1, "error\n", 6);
	exit(1);
}

int	syntax_error(char *s)
{
	if (!(*s) == '+' || *s == '-' || (*s >= '0' && *s <= '9'))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate_error(t_node *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == num)
			return (1);
		a = a->next;
	}
	return (0);
}
