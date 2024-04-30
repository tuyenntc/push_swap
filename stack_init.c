#include "push_swap.h"

/***************************************************************************************************
*
*
*
****************************************************************************************************/


//overflow? conver str to long value
static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = (result * 10) + (*s++ - '0');
	return (result * sign);
}


//create stack a with values from cmd input (check duplicated values, over/under flow/ syntax errors)

void	stack_init(t_node **a, char **av)
{
	long nbr;
	int	i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a);
		if (duplicate_error(*a, (int)nbr))
			free_error(a);
		insert_end(a, (int)nbr);
		i++;
	}
}


static void	insert_end(t_node **stack, int n)
{
	t_node	*new;
	t_node	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return;
	new->next = NULL;
	new->nbr = n;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = new;
		new->prev = last;
	}
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
}
