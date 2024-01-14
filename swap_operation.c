#include "push_swap.h"
// swap operation
void swap(stack **s)
{
    stack  *tmp;

    tmp = *s;
    *s = (*s)->next;
    tmp->next = (*s)->next;
    (*s)->next = tmp;
}

void swap_a(stack **a)
{
    swap(a);
    ft_putstr_fd("sa\n", 1);   
}
void swap_b(stack **b)
{
    swap(b);
    ft_putstr_fd("sb\n", 1);   
}
void swap_ab(stack **a, stack **b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 1);
}


