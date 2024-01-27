/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:31 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:57:33 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include "../lib/libft/libft.h"

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
int ft_stack_size(stack *s);
stack * get_min_in_stack(stack *s);

// SET UP THE STACK NODES
void set_index_to_node(stack *s);
void set_node_to_push(stack *a, stack *b);
int calculate_price(stack *a, stack *b, stack *chosen_node, stack *target_node);
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
void swap_a(stack **a, int true);
void swap_b(stack **b, int true);
void swap_ab(stack **a, stack **b, int true);
// PUSH
void push(stack **s, stack *top);
stack *pop(stack **s);
void push_a(stack **a, stack **b, int true);
void push_b(stack **a, stack **b, int true);
// ROTATE
void rotate(stack **s);
void rotate_a(stack **a, int true);
void rotate_b(stack **b, int true);
void rotate_ab(stack **a, stack **b, int true);
// REVERSE ROTATE
void reverse_rotate(stack **s);
void reverse_rotate_a(stack **a, int true);
void reverse_rotate_b(stack **b, int true);
void reverse_rotate_ab(stack **a, stack **b, int true);

// CHECKER 
//void execute_operation(stack **a, stack **b, char *operation);
void execute_instructions(stack **a, stack **b);

// FREE
void free_vector(char **av);
void free_stack (stack *head);

#endif