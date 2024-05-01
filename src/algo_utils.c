/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:31:39 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/02 04:42:26 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	exist_in_a(t_stack *a, int value)
{
	while (a)
	{
		if (a->data == value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	divider(t_stack *a)
{
	if (ft_stack_size(a) >= 500)
		return (13);
	return (5);
}

t_stack	*get_last_node(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

void	fix_stack_b(t_stack **b, t_param param)
{
	if (ft_stack_size(*b) > 1 && (*b)->data <= param.array[param.mid])
	{
		rotate_b(b, 1);
	}
}

int	*dup_array(t_stack *a)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * ft_stack_size(a));
	if (array == NULL)
		return (NULL);
	while (a)
	{
		array[i] = a->data;
		i++;
		a = a->next;
	}
	return (array);
}
