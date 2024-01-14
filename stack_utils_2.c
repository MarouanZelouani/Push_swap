#include "push_swap.h"

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
            b->target = get_min_in_stack(a);
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
int calculate_price(stack *a, stack *b)
{
    int stack_a_size;
    int stack_b_size;    
    int total_price;

    stack_a_size = ft_stack_size(a);
    stack_b_size = ft_stack_size(b);
    total_price = 0;
    if (a->index < stack_a_size / 2)
        total_price += a->index;
    else 
        total_price += stack_a_size - a->index;
    if (b->index < stack_b_size / 2)
        total_price += b->index;
    else 
        total_price += stack_b_size - b->index;
    return total_price;
}

void set_node_to_push(stack *a, stack *b)
{
    stack *chosen_node;
    int min_price;

    chosen_node = NULL;
    while (b != NULL)
    {
        // NEED TOBE FIXED
        // if (calculate_price(b, get_node(a, b->target)) < calculate_price(b->next, get_node(a, (b->next)->target)))
        //     chosen_node = b;

        // FIXED
        if (chosen_node == NULL || calculate_price(b, get_node(a, b->target)) < calculate_price(chosen_node, get_node(a, chosen_node->target)))
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

// MOVE FUNCTION