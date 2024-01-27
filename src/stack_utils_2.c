/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:24 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:58:25 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack * get_min_in_stack(stack *s)
{
    stack *min;

    min = s;
    s = s->next;
    while (s != NULL)
    {
        if (s->data < min->data)
            min = s;
        s = s->next;
    }
    return min;
}

void set_target(stack *a, stack *b)
{
    long target_index;
    stack *current;

    while (b != NULL)
    {
        target_index = LONG_MAX;
        current = a;
        while (current != NULL)
        {
            if (current->data > b->data && current->data < target_index)
                target_index = current->data;
            current = current->next;
        }
        if (target_index == LONG_MAX)
            b->target = get_min_in_stack(a)->data;
        else
            b->target = target_index;
        b = b->next;
    }
}

stack *get_node(stack *s, int data)
{
    stack *node;

    node = NULL;
    while (s != NULL)
    {
        if (s->data == data)
        {
            node = s;
            break;
        }
        s = s->next;
    }
    return node;
}
int calculate_price(stack *a, stack *b, stack *chosen_node, stack *target_node)
{
    int stack_a_size;
    int stack_b_size;    
    int total_price;

    stack_a_size = ft_stack_size(a);
    stack_b_size = ft_stack_size(b);
    total_price = 0;
    if (chosen_node->index <= stack_b_size / 2)
        total_price += chosen_node->index;
    else 
        total_price += stack_b_size - chosen_node->index;
    if (target_node->index <= stack_a_size / 2)
        total_price += target_node->index;
    else 
        total_price += stack_a_size - target_node->index;
    return total_price;
}

void set_node_to_push(stack *a, stack *b)
{
    stack *chosen_node;
    stack *head;

    head = b;
    chosen_node = NULL;
    while (b != NULL)
    {
        if (chosen_node == NULL || 
        calculate_price(a, head, b, get_node(a, b->target)) < calculate_price(a, head, chosen_node, get_node(a, chosen_node->target)))
            chosen_node = b;
        b = b->next;
    }
    if (chosen_node != NULL)
        chosen_node->to_push = 1;
}   

void set_index_to_node(stack *s)
{
    int i;

    i = 0;
    while (s != NULL)
    {
        s->index = i;
        i++;
        s = s->next;
    }
}