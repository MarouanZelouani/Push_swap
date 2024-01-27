/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:00 by mzelouan          #+#    #+#             */
/*   Updated: 2024/01/26 08:57:01 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int main (int ac, char **args)
{
    int i;
    char **av;
    char *str;
    stack *stack_a;
    stack *stack_b;

    i = 1;
    str = NULL;
    stack_a = NULL;
    stack_b = NULL;
    if (ac < 1 && args[1][0] == '\0')
        return (0);
    while (i < ac)
    {
        str = ft_strjoin(str, " ");
        str = ft_strjoin(str, args[i]);
        i++;
    }
    av = ft_split(str, ' ');
    free(str);
    if(!is_all_digits(av) || !exist_duplicates(av))
    {
        ft_putstr_fd("Error\n", 2);
        free_vector(av);
        return (0);
    }
    init_stack(&stack_a, av);
    free_vector(av);
    execute_instructions(&stack_a, &stack_b);
    if(is_sorted(stack_a) && stack_b == NULL)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    free_stack (stack_a);   
}
