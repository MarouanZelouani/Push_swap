/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:02 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:58:03 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void push_a(stack **a, stack **b, int true)
{
    stack *top;

    top = pop(b);
    if (top == NULL)
        return ;
    push(a, top);
    if (true)
        ft_putstr_fd("pa\n", 1);
}

void push_b(stack **a, stack **b, int true)
{
    stack *top;

    top = pop(a);
    if (top == NULL)
        return ;
    push(b, top);
    if (true)
        ft_putstr_fd("pb\n", 1);
}



