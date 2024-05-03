#include "push_swap.h"


/*****************************************************************************************************************************
* check all input conditions: number of ac: 2 --> likely the 2nd argument is a string --> handle it; valid ac (empty string) *
* initiate the stack and sort (3 numbers or more)
* dont forget to free stack at the end
* ./push_swap 12 4 35
* ./push_swap 12 -42 66
* ./push_swap "12 4 35"
* ./push_swap --32
* ./push_swap abc
* ./push_swap 12 c 44
* ./push_swap "12 c 44"
******************************************************************************************************************************/

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
//	else if (ac == 2 && av[1] != NULL && av[1][0] != '\0')
	else if (ac == 2)
		av = split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	deallocate(&a);
	return (0);
}
