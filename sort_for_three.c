#include "push_swap.h"

int is_the_greater(stack *s, stack *to_test)
{
    while (s != NULL)
    {
        if (s->data > to_test->data)
            return (0);
        s = s->next;
    }
    return (1);
}

void sort_three(stack **a)
{
    if (is_the_greater(*a, *a))
        rotate_a(a);
    else if (is_the_greater(*a, (*a)->next))
        reverse_rotate_a(a);
    if ((*a)->data > ((*a)->next)->data)
        swap_a(a);
}
