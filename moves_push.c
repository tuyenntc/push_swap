#include "push_swap.h"
#include <stdio.h>

static void push(t_node **dst, t_node **src);

//push a node to the top from src to dst (from stack a-> b OR from stack b -> a) - if stack is empty (NULL)?

/*
int main()
{
    t_node *first = (t_node *)malloc(sizeof(t_node));
    t_node *second = (t_node *)malloc(sizeof(t_node));
    t_node *third = (t_node *)malloc(sizeof(t_node));

    if (!first || !second || !third)
    {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    first->nbr = 1;
    first->prev = NULL;
    first->next = NULL;

    second->nbr = 2;
    second->prev = NULL;
    second->next = NULL;

    third->nbr = 3;
    third->prev = NULL;
    third->next = NULL;

    t_node *src_head = first;
    t_node *dst_head = NULL;

    printf("Initial src_head: %d\n", src_head->nbr); // Debug print
    printf("Initial dst_head: %p\n", (void *)dst_head); // Debug print

    push(&dst_head, &src_head);
    printf("After first push - src_head: %p, dst_head: %d\n", (void *)src_head, dst_head->nbr); // Debug print

    push(&dst_head, &src_head);
    printf("After second push - src_head: %p, dst_head: %d\n", (void *)src_head, dst_head->nbr); // Debug print

    push(&dst_head, &src_head);
    printf("After third push - src_head: %p, dst_head: %d\n", (void *)src_head, dst_head->nbr); // Debug print

    printf("Destination list after pushing nodes:\n");
    t_node *current = dst_head;
    // Print nodes from dst
    while (current)
    {
        printf("%d -> ", current->nbr);
        current = current->next;
    }
    printf("NULL\n");

    // Free allocated memory
    free(first);
    free(second);
    free(third);

    return EXIT_SUCCESS;
}

*/

static void	push(t_node **dst, t_node **src)
{
	t_node	*new_node;
	if (!*src)
		return ;
	new_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new_node->prev = NULL;
	if (!*dst)
	{
		*dst = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dst;
		new_node->next->prev = new_node;
		*dst = new_node;
	}
}



void	pa(t_node **a, t_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}

