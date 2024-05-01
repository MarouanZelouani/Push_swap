/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:15:39 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/01 13:49:43 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_min_in_stack(t_stack *s)
{
	t_stack	*min;

	min = s;
	s = s->next;
	while (s != NULL)
	{
		if (s->data < min->data)
			min = s;
		s = s->next;
	}
	return (min);
}

t_stack	*get_node(t_stack *s, int data)
{
	t_stack	*node;

	node = NULL;
	while (s != NULL)
	{
		if (s->data == data)
		{
			node = s;
			break ;
		}
		s = s->next;
	}
	return (node);
}

void	set_index_to_node(t_stack *s)
{
	int	i;

	i = 0;
	while (s != NULL)
	{
		s->index = i;
		i++;
		s = s->next;
	}
}

t_stack	*get_max_in_stack(t_stack *s)
{
	t_stack	*max;

	max = s;
	s = s->next;
	while (s != NULL)
	{
		if (s->data > max->data)
			max = s;
		s = s->next;
	}
	return (max);
}
