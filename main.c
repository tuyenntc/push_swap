#include "push_swap.h"


/*****************************************************************************************************************************
* check all input conditions: number of ac: 2 --> likely the 2nd argument is a string --> handle it; valid ac (empty string) *
* initiate the stack and sort (3 numbers or more)
* dont forget to free stack at the end
******************************************************************************************************************************/

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	stack_init(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
