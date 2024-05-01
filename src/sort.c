/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:19 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/07 14:24:29 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 2)
		swap_a(a, 1);
	else if (ft_stack_size(*a) == 3)
		sort_three(a);
	else if (ft_stack_size(*a) == 4 || ft_stack_size(*a) == 5)
		sort_five(a, b);
	else
		sort(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
	{
		set_index_to_node(*a);
		while ((*a)->data != get_min_in_stack(*a)->data)
		{
			if (get_min_in_stack(*a)->index <= ft_stack_size(*a) / 2)
				rotate_a(a, 1);
			else
				reverse_rotate_a(a, 1);
		}
		push_b(a, b, 1);
	}
	sort_three(a);
	while (*b)
		push_a(a, b, 1);
}

void	insertion_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	belong_to_the_range(int value, t_param param)
{
	int	i;

	i = param.start;
	if (param.start < 0)
		i = 0;
	while (i <= param.end)
	{
		if (value == param.array[i])
			return (1);
		i++;
	}
	return (0);
}

int	return_first_match(t_stack *a, t_param param)
{
	int	first_match;

	first_match = a->data;
	if (belong_to_the_range(first_match, param))
		return (first_match);
	a = a->next;
	while (a)
	{
		if (belong_to_the_range(a->data, param))
			return (a->data);
		a = a->next;
	}
	return (first_match);
}
