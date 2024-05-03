#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_node	*target_node;
	struct	s_node	*next;
	struct	s_node	*prev;
}	t_node;

//handle input
char	**split(char *input, char c);

// errors
void	free_str(char **av);
void	deallocate(t_node **head);
//void	free_stack(t_node **stack);
void	free_all(t_node **a, char **av, bool flag_ac_str);
int		syntax_error(char *s);
int		duplicate_error(t_node *a, int number);


//initiate stack
static long	ft_atol(const char *s);
void		stack_init(t_node **a, char **av, bool flag_ac_str);
static void	insert_end(t_node **stack, int value);
t_node		*get_cheapest(t_node *stack);
void	prep_for_push(t_node **stack, t_node *top_node, char stack_name);
//init_a_to_b
void	current_index(t_node *stack);
static void	set_target_a(t_node *a, t_node *b);
static void	cost_analysis_a(t_node *a, t_node *b);
void	set_cheapest(t_node *stack);
void	init_nodes_a(t_node *a, t_node *b);

//init_b_to_a
static void	set_target_b(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);

//utils_linked list
int	stack_len(t_node *head);
bool	stack_sorted(t_node *stack);
t_node	*find_last(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);

//sorting
void	sort_three(t_node **a);
void	sort_stacks(t_node **a, t_node **b);
static void	rotate_both(t_node **a, t_node **b, t_node *cheapest);
static void	rev_rot_both(t_node **a, t_node **b, t_node *cheapest);
static void move_a_to_b(t_node **a, t_node **b);
static void	move_b_to_a(t_node **a, t_node **b);
static void	min_on_top(t_node **a);

//moves:
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
