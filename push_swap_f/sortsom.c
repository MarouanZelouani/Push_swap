#include "../includes/push_swap.h"

void push_in_b (stack **a, stack **b)
{
    stack *tmp;
    int rotation_number;
    while (ft_stack_size(*a) > 3)
    {
        tmp = *a;
        rotation_number = count_rotation_for_ab(*a, *b);
        while (rotation_number >= 0)
        {
            
            tmp = tmp->next;
        }
    }
}

void push_in_b_and_sort (stack **a, stack **b)
{
    if (ft_stack_size(*a) > 3)
        push_b(a, b, 1);
    if (ft_stack_size(*a) > 3)
        push_b(a, b, 1);
    if (ft_stack_size(*a) > 3)
        push_in_b(a, b);
    sort_three(a);
}

void push_back_in_a_and_sort (stack **a, stack **b)
{

}

void sorte_for_500 (stack ** a, stack **b)
{
    push_in_b_and_sort(a, b);
    push_back_in_a_and_sort(a, b);
    send_min_node_to_top(a);
}