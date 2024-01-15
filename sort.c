#include "push_swap.h"


// MARKE THE CHOSEN NODE (TOBE PUSHED FROM B TO A) 
void set_up_nodes(stack *a, stack *b)
{
    set_index_to_node(a);
    set_index_to_node(b);
    set_target(a, b);
    set_node_to_push(a, b);
}

stack *get_to_push_node(stack *s)
{
    stack *to_push;

    to_push = NULL;
    while(s != NULL)
    {
        if(s->to_push)
        {
            to_push = s;
            break;
        }
        s = s->next;
    }
    return to_push;
}

// PUSH THE CHOSEN NODE (THAT HAVE THE SMALLEST  PRICE) TO A
// ROTATE INTIL THE CHOSEN NODE AND ITS TARGET ARE ON TOP OF THERE STACKS 
void move_chosen_node(stack **a, stack **b)
{
    int stack_a_size;
    int stack_b_size;
    stack *to_push;
    stack *target;

    to_push = get_to_push_node(*b);
    target = get_node(*a, to_push->target);
    stack_a_size = ft_stack_size(*a);
    stack_b_size = ft_stack_size(*b);
    if (to_push->index > stack_b_size / 2 && target->index > stack_a_size / 2)
        case_1(to_push, target, a, b);
    else if (to_push->index > stack_b_size / 2 && target->index < stack_a_size / 2)
        case_2(to_push, target, a, b);
    else if (to_push->index < stack_b_size / 2 && target->index > stack_a_size / 2)
        case_3(to_push, target, a, b);
    else 
        case_4(to_push, target, a, b);
    push_a(a, b);
}

void sort_stack(stack **a, stack **b)
{
    if (ft_stack_size(*a) == 2)
        swap_a(a);
    else if (ft_stack_size(*a) == 3)
        sort_three(a);
    else if (ft_stack_size(*a) <= 5)
        printf("sort stack");
    else 
    {
        while (ft_stack_size(*a) > 3)
            push_b(a, b);
        sort_three(a);
        while(*b)
        {
            set_up_nodes(*a, *b);
            move_chosen_node(a, b);
        }
        set_index_to_node(*a);
        if (get_min_in_stack(*a)->index > ft_stack_size(*a) / 2)
        {
            while (get_min_in_stack(*a)->index != 0)
                rotate_a(a);
        }
        else 
        {
            while (get_min_in_stack(*a)->index != 0)
                reverse_rotate_a(a);
        }
    }       
}

