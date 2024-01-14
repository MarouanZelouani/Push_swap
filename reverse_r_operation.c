#include "push_swap.h"

void reverse_rotate(stack **s)
{
    stack *secondLast;
    stack *last;

    last = *s;
    secondLast = NULL;
    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }
    secondLast->next = NULL;
    last->next = *s;
    *s = last;
}

void reverse_rotate_a(stack **a)
{
    reverse_rotate(a);
    ft_putstr_fd("rra\n", 1);
}
void reverse_rotate_b(stack **b)
{
    reverse_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}
void reverse_rotate_ab(stack **a, stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}