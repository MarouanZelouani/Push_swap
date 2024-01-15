#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "./libft/libft.h"

typedef struct t_stack
{
    int data;
    int index;
    int to_push;
    int target;
    struct t_stack *next;
} stack;

// STACK MANIPULATION
void init_stack(stack **stack_a, char **av);
int is_all_digits(char **av);
int exist_duplicates (char **av);
int is_sorted(stack *s);
void print_stack(stack *s);
int ft_stack_size(stack *s);
stack * get_min_in_stack(stack *s);

// SET UP THE STACK NODES
void set_index_to_node(stack *s);
void set_node_to_push(stack *a, stack *b);
int calculate_price(stack *a, stack *b);
stack *get_node(stack *s, int data);
void set_target(stack *a, stack *b);
stack * get_min_in_stack(stack *s);
void set_up_nodes(stack *a, stack *b);

// PUSH CASES
void case_1 (stack *to_push, stack *target, stack **a, stack **b);
void case_2 (stack *to_push, stack *target, stack **a, stack **b);
void case_3 (stack *to_push, stack *target, stack **a, stack **b);
void case_4 (stack *to_push, stack *target, stack **a, stack **b);

// SORTING PART
void sort_three(stack **a);
void sort_stack(stack **a, stack **b);
// void sort_five(stack **a, stack **b);
void sort_stack(stack **a, stack **b);
void move_chosen_node(stack **a, stack **b);


// SORTING OPERATIONS
// SWAP
void swap(stack **s);
void swap_a(stack **a);
void swap_b(stack **b);
void swap_ab(stack **a, stack **b);
// PUSH
void push(stack **s, stack *top);
stack *pop(stack **s);
void push_a(stack **a, stack **b);
void push_b(stack **a, stack **b);
// ROTATE
void rotate(stack **s);
void rotate_a(stack **a);
void rotate_b(stack **b);
void rotate_ab(stack **a, stack **b);
// REVERSE ROTATE
void reverse_rotate(stack **s);
void reverse_rotate_a(stack **a);
void reverse_rotate_b(stack **b);
void reverse_rotate_ab(stack **a, stack **b);

#endif