#include "push_swap.h"
#include "stdio.h"

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
/*
int main(void)
{
	const char *test[] = {
		"12345", 
		"-66312",
		"0",
		"  123   ",
		"  -222  ",
		"abc",
		"  +111 ",
		"",
		NULL
	};
	for (int i = 0; test[i] != NULL; i++)
	{
		const char	*input = test[i];
		long result = ft_atol(input);
		printf("input: \"%s\" _ output: %ld\n", input, result);
	}
	return (0);
}

*/
//create stack a with values from cmd input (check duplicated values, over/under flow/ syntax errors)

static void	insert_end(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;
	if (!stack)
		return;
	new = malloc(sizeof(t_node));
	if (!new)
		return;
	new->next = NULL;
	new->nbr = value;
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

void	stack_init(t_node **a, char **av)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a, av);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_error(a, av);
		if (duplicate_error(*a, (int)nb))
			free_error(a, av);
		insert_end(a, (int)nb);
		++i;
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
	{
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
}

/*
int	main()
{
	t_node	*a = NULL;
	printf("%p pointer from main initially\n", a);
	char *arr[5] = {
		arr[0] = "\0",
		arr[1] = "20",
		arr[2] = "99",
		arr[3] = "-7",
		arr[4] = NULL};
	stack_init(&a, arr + 1);
	while (a)
	{
		printf("\n%d, \t node with address %p\n", a->nbr, a);
		a = a->next;
	}
}
*/
