#include "../includes/push_swap.h"

// ALL INSTRUCTIONs CASES

// to_push->index > MID_B && target->index > MID_A
void case_4 (stack *to_push, stack *target, stack **a, stack **b)
{
    while (to_push->index != 0 && target->index != 0)
    {
        rotate_ab(a, b);
        set_index_to_node(*a);
        set_index_to_node(*b);
    }
    if (to_push->index == 0)
    {
        while (target->index != 0)
        {
            rotate_a(a);
            set_index_to_node(*a);
        }
    }
    else
    {
        while (to_push->index != 0)
        {
            rotate_b(b);
            set_index_to_node(*b);
        }
    }
}

// to_push->index > MID_B && target->index < MID_A
void case_3 (stack *to_push, stack *target, stack **a, stack **b)
{
    while (to_push->index != 0)
    {
        rotate_b(b);
        set_index_to_node(*b);
    }
    while (target->index != 0)
    {
        reverse_rotate_a(a);
        set_index_to_node(*a);
    }
}

// to_push->index < MID_B && target->index > MID_A
void case_2 (stack *to_push, stack *target, stack **a, stack **b)
{
    while (to_push->index != 0)
    {
        reverse_rotate_b(b);
        set_index_to_node(*b);
    }
    while (target->index != 0)
    {
        rotate_a(a);
        set_index_to_node(*a);
    }
}

// to_push->index < MID_B && target->index < MID_A
void case_1 (stack *to_push, stack *target, stack **a, stack **b)
{
    while (to_push->index != 0 && target->index != 0)
    {
        reverse_rotate_ab(a, b);
        set_index_to_node(*a);
        set_index_to_node(*b);
    }
    if (to_push->index == 0)
    {
        while (target->index != 0)
        {
            reverse_rotate_a(a);
            set_index_to_node(*a);
        }
    }
    else
    {
        while (to_push->index != 0)
        {
            reverse_rotate_b(b);
            set_index_to_node(*b);
        }
    }
}