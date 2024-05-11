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

/*
int main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("usage: %s <num1> <num2> <num3> \n", av[0]);
		return (1);
	}
	int num1 = atoi(av[1]);
	int num2 = atoi(av[2]);
	int num3 = atoi(av[3]);
	t_node *node1 = (t_node *)malloc(sizeof(t_node));
	t_node *node2 = (t_node *)malloc(sizeof(t_node));
	t_node *node3 = (t_node *)malloc(sizeof(t_node));
	if (!node1 || !node2 || !node3)
	{
		printf("failed memory allocation\n");
		exit(1);
	}
	node1->nbr = num1;
	node2->nbr = num2;
	node3->nbr = num3;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	sort_three(&node1);
	printf("sorted list: %d -> %d -> %d\n", node1->nbr, node1->next->nbr, node1->next->next->nbr);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
