#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rot_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rot_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (!find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
/*
void	sort_big_stack(t_node **a, t_node **b)
{
	int	len_a;
	len_a = stack_len(*a);
	
	while (len_a > 3 && !stack_sorted(*a))
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a, false);
		if ((*a)->nbr > (*a)->next->next->nbr)
			rra(a, false);
		if (!stack_sort(*a))
			pb(b, a, false);
		len_a--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, false);
	current_index(*a);
	min_on_top(a);
}
*/
void	sort_stacks(t_node **a, t_node **b)
{
	int	len_a;
	len_a = stack_len(*a);
//	if (len_a-- > 3 && !stack_sorted(*a))
//		pb(b, a, false);
//	if (len_a-- > 3 && !stack_sorted(*a))
//		pb(b, a, false);
//	while (len_a-- > 3 && !stack_sorted(*a))
//	{
//		init_nodes_a(*a, *b);
//		move_a_to_b(a, b);
//	}
//	sort_three(a);
//	while (*b)
//	{
//		init_nodes_b(*a, *b);
//		move_b_to_a(a, b);
//	}
//	current_index(*a);
//	min_on_top(a);
	while (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
