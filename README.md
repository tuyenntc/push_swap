Implementation of linked list to sort 2 stacks with random numbers:
1. Implement 2 stack A, B. Random numbers are on stack A, using stack B (to temporarily move numbers from A to B) when sorting more than 3 numbers. After finish sorting, all numbers must be on A and B is empty
2. implement moves: 

sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 

sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 

ss : sa and sb at the same time. 

pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty. 

pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty. 

ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 

rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 

rr : ra and rb at the same time. 

rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 

rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 

rrr : rra and rrb at the same time.
