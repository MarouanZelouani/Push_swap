/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:56:54 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/05 03:49:49 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**push_swap(int ac, char **args)
{
	char	*str;
	char	**av;
	int		i;

	i = 1;
	str = NULL;
	av = NULL;
	while (i < ac)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, args[i]);
		i++;
	}
	av = ft_split(str, ' ');
	free(str);
	if (!is_all_digits(av) || !exist_duplicates(av))
	{
		ft_putstr_fd("Error\n", 2);
		free_vector(av);
		exit(-1);
	}
	return (av);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;
	int	empty;

	i = 1;
	while (i < ac)
	{
		empty = 0;
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				empty = 1;
			j++;
		}
		if (empty == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		i++;
	}
}

int	main(int ac, char **args)
{
	char	**av;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (-1);
	check_args(ac, args);
	av = push_swap(ac, args);
	init_stack(&stack_a, av);
	free_vector(av);
	if (!dup_checker (stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack (stack_a);
		return (-1);
	}
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	exit(0);
}
