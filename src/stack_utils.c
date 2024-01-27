/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:28 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:58:29 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack *ft_new_stack_node(int data, int index)
{
	stack	*node;

	node = (stack *)malloc(sizeof(stack));
	if (node == NULL)
		return (0);
	node->data = data;
    node->index = index;
    node->to_push = 0;
	node->next = NULL;
	return (node);
}

int ft_stack_size(stack *s)
{
    if (s == NULL)
        return (0);
    return (1 + ft_stack_size(s->next));
}

void ft_stack_add_back (stack **s, stack *new)
{
    stack	*node;

	if (new != NULL)
	{
		if (*s == NULL)
			*s = new;
		else
		{
			node = *s;
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = new;
		}
	}
}

void init_stack(stack **stack_a, char ** av)
{
    int i;
    long cheker;
    stack *holder;
    int index;

    i = 0;
    index = 0;
    holder = NULL;
    while (av[i])
    {
        cheker = ft_atoi(av[i]);
        if (!(cheker >= INT_MIN && cheker <= INT_MAX))
        {
            ft_putstr_fd("Error\n", 2);
            free_vector(av);
            free_stack(*stack_a);
            exit(1);
        }
        holder = ft_new_stack_node(cheker, index);
        ft_stack_add_back(stack_a, holder);
        i++;
        index++;
    }
}



