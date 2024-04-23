#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node	*target_node;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
}	t_node;

//handle input
char	**split(char *s, char c);

//handle errors
void	free_matrix(char **av);
void	error_free(t_node **a, char **av, bool flag_ac_2);
void	free_stack(t_node **stack);
int		error_repetition(t_node *a, int nbr);
int		error_syntax(char *str_nbr);

//initiate stack
void	stack_init(t_node **a, char **av, bool flag_ac_2);
void	node_inits(t_node *a, t_node *b);
void	set_current_position(t_node *stack);
void	set_price(t_node *a, t_node *b);
void	set_cheapest(t_node *b);

//utils_linked list
void			append_node(t_node **stack, int n);
t_node	*find_last_node(t_node *head);
t_node	*find_smallest(t_node *stack);
t_node	*return_cheapest(t_node *stack);
bool			stack_sorted(t_node *stack);
int				stack_len(t_node *stack);
void			finish_rotation(t_node *ss, t_node *n, char c);

//chunk sorting
void	tiny_sort(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);

//moves/ actions:
void	sa(t_node **a, bool checker);
void	sb(t_node **b, bool checker);
void	ss(t_node **a, t_node **b, bool checker);

void	ra(t_node **a, bool checker);
void	rb(t_node **b, bool checker);
void	rr(t_node **a, t_node **b, bool checker);

void	rra(t_node **a, bool checker);
void	rrb(t_node **b, bool checker);
void	rrr(t_node **a, t_node **b, bool checker);

void	pa(t_node **a, t_node **b, bool checker);
void	pb(t_node **a, t_node **b, bool checker);








#endif
