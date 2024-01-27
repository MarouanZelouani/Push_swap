/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:32 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:58:33 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// swap operation
void swap(stack **s)
{
    stack  *tmp;

    tmp = *s;
    *s = (*s)->next;
    tmp->next = (*s)->next;
    (*s)->next = tmp;
}

void swap_a(stack **a, int true)
{
    swap(a);
    if(true)
        ft_putstr_fd("sa\n", 1);   
}
void swap_b(stack **b, int true)
{
    swap(b);
    if (true)
        ft_putstr_fd("sb\n", 1);   
}
void swap_ab(stack **a, stack **b, int true)
{
    swap(a);
    swap(b);
    if (true)
        ft_putstr_fd("ss\n", 1);
}


