#include "push_swap.h"

/*
3 - 1 - 2 					-->ra	--> 1 - 2 - 3
1 - 3 - 2 OR 2 - 3 - 1 		-->rra	--> 1 - 2 - 3 (sorted) || 2 - 1 - 3 (unsorted) 
															--> sa --> 1 - 2 - 3

*/


void	sort_three(t_node **a)
{
	t_node	*biggest;
	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, false);
	else if ((*a)->next == biggest)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
