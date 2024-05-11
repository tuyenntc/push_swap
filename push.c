#include "push_swap.h"
#include <stdio.h>

//push a node to the top from src to dst (from stack a-> b OR from stack b -> a) - if stack is empty (NULL)?

/*

*/

static void	push(t_node **dst, t_node **src)
{
	t_node	*new;
	if (!*src)
		return ;
	new = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new->prev = NULL;
	if (!*dst)
	{
		*dst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *dst;
		new->next->prev = new;
		*dst = new;
	}
}

void	pa(t_node **a, t_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
/*
int main(void)
{
	t_node	*dst = NULL;
	t_node	*src = NULL;
	for (int i = 0; i < 5; i++)
	{
		t_node	*new = (t_node *)malloc(sizeof(t_node));
		if (!new)
		{
			perror("memory allocation fails");
			exit(EXIT_FAILURE);
		}
		new->nbr = i + 1;
		new->prev = NULL;
		new->next = src;
		if (src)
			src->prev = new;
		src = new;
	}
	printf("src stack before push: \n");
	t_node	*current = src;
	while (current)
	{
		printf("%d", current->nbr);
		current = current->next;
	}
	printf("\n");
	push(&dst, &src);
	printf("Dst stack after push:\n");
    current = dst;
    while (current) {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n");

    // Print contents of src stack after push
    printf("Src stack after push:\n");
    current = src;
    while (current) {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n");

    // Free dynamically allocated memory
    while (src) {
        t_node *temp = src;
        src = src->next;
        free(temp);
    }
    while (dst) {
        t_node *temp = dst;
        dst = dst->next;
        free(temp);
    }

    return 0;
}
*/
