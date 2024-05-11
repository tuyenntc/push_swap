#include "push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}
/*
for each node/ value in a, find a target in b which is the closet smaller - so you kknow where to push it (in b - descending order - big to small) but in a (ascending order) or MAX value if there is none



*/
static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match_index;
	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node = NULL;
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	init_nodes_a(t_node *a, t_node *b)
{
	if (!a || !b)
	{
		printf("error: empty list\n");
		return;
	}
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
/*
int main()
{
	t_node	*a = NULL;
	t_node	*b = NULL;
	for (int i = 1; i <= 10; ++i)
	{
		t_node *new = (t_node *)malloc(sizeof(t_node));
		if (!new)
		{
			printf("memory allocation failed\n");
			return (1);
		}
		new->nbr = i;
		new->next = a;
		a = new;
	}
	printf("Before initialization:\n");
    printf("Stack 'a' length: %d\n", stack_len(a));
    printf("Stack 'b' length: %d\n", stack_len(b));

    // Initialize nodes in stacks 'a' and 'b'
    printf("Initializing nodes...\n");
    init_nodes_a(a, b);

    // Print information after initialization
    printf("After initialization:\n");
    printf("Stack 'a' length: %d\n", stack_len(a));
    printf("Stack 'b' length: %d\n", stack_len(b));

	printf("node infor: \n");
	t_node *current = a;
	while (current)
	{
		printf("value: %d, index: %d, above_median: %d, push cost: %d, cheapest: %d\n", current->nbr, current->index, current->above_median, current->push_cost, current->cheapest);
	current = current->next;
	}
	while (a)
	{
		t_node *tmp = a;
		a = a->next;
		free(tmp);
	}
	return (0);
}
*/
