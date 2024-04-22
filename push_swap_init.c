#include "push_swap.h"

//set current position of every node
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	mid_line;

	i = 0;
	if (stack == NULL)
		return ;
	mid_line = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i < mid_line)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

//find the target node in a from b - candidate: smallest-bigger?? second smalless node? if no bigger value, find the smallest
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

//price to push from b -> a - position of the node will decide how costly to move it - set the price
void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

//find the cheapest node to move and flag it
void	set_cheapest(t_stack_node *b)
{
	long	best_match_value;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

//relative position - target node - price - cheapest --> ready to make the move
void	init_node(t_stack_node *a, t_stack_node *b)
{
	set_current_postition(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
