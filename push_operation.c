#include "push_swap.h"

// PUSH OPERATION
void push(stack **s, stack *top)
{
    top->next = *s;
    *s = top;
}

stack *pop(stack **s)
{
    stack *tmp;

    tmp = *s;
    *s = (*s)->next;
    return tmp;
}

void push_a(stack **a, stack **b)
{
    stack *top;

    top = pop(b);
    if (top == NULL)
        return ;
    push(a, top);
    ft_putstr_fd("pa\n", 1);
}

void push_b(stack **a, stack **b)
{
    stack *top;

    top = pop(a);
    if (top == NULL)
        return ;
    push(b, top);
    ft_putstr_fd("pb\n", 1);
}



