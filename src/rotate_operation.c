#include "../includes/push_swap.h"

// ROTATING A STACK  (the first element becames the last and others shift up to the top by one place)
void  rotate (stack **s)
{
    stack *first;
    stack *secound;
    stack *current;

    first = *s;
    secound = (*s)->next;
    current = secound;

    while (current->next != NULL)
        current = current->next;

    first->next = NULL;
    current->next = first;
    *s = secound;
}

void rotate_a(stack **a)
{
    rotate(a);
    ft_putstr_fd("ra\n", 1);
}

void rotate_b(stack **b)
{
    rotate(b);
    ft_putstr_fd("rb\n", 1);
}

void rotate_ab(stack **a, stack **b)
{
    rotate(a);
    rotate(b);
    ft_putstr_fd("rr\n", 1);
}