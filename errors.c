#include "push_swap.h"

//free the whole linked list

void	deallocate(t_node **head)
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
}


void	free_str(char **av)
{
	int	i;
	i = 0; //-1
	if (av == NULL || *av == NULL)
		return;
	while (av[i])
		free(av[i++]);
	free(av); //av - 1
}

/*
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
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
*/
void	free_all(t_node **a, char **av, bool flag_ac_str)
{
	deallocate(a);
	if (flag_ac_str)
		free_str(av);
	write(2, "error\n", 6);
	exit(1);
}

int	syntax_error(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
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
