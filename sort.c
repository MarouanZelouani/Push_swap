#include "push_swap.h"


// MARKE THE CHOSEN NODE (TOBE PUSHED FROM B TO A) 
void set_up_nodes(stack *a, stack *b)
{

}

// PUSH THE CHOSEN NODE (THAT HAVE THE SMALLEST  PRICE) TO A
// ROTATE INTIL THE CHOSEN NODE AND ITS TARGET ARE ON TOP OF THERE STACKS 
void move_chosen_node(stack **a, stack **b)
{
    
    push_a(a, b);
}

void sort_stack(stack **a, stack **b)
{
    if (ft_stack_size(*a) == 2)
        swap_a(a);
    else if (ft_stack_size(*a) == 3)
        sort_three(a);
    else if (ft_stack_size(*a) <= 5)
        sort_five(a, b);
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
    }       
}