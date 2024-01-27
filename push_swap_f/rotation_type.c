#include "../includes/push_swap.h"

int count_rotation_for_ab(stack *a, stack *b)
{
    int count;
    stack *tmp;
    
    tmp = a;
    count = case_rrarrb(a, b, a->nbr);
    while(tmp)
    {

        tmp = tmp->next;
    }
    return (count);
}