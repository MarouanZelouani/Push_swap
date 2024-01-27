/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:11 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:58:12 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void rotate_a(stack **a, int true)
{
    rotate(a);
    if (true)
        ft_putstr_fd("ra\n", 1);
}

void rotate_b(stack **b, int true)
{
    rotate(b);
    if (true)
        ft_putstr_fd("rb\n", 1);
}

void rotate_ab(stack **a, stack **b, int true)
{
    rotate(a);
    rotate(b);
    if(true)
        ft_putstr_fd("rr\n", 1);
}