#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void execute_operation(stack **a, stack **b, char *operation)
{
    if (ft_strcmp(operation, "sa"))
        swap_a(a);
    else if (ft_strcmp(operation, "sb"))
        swap_b(b);
    else if (ft_strcmp(operation, "ss"))
        swap_ab(a, b);
    else if (ft_strcmp(operation, "pa"))
        push_a(a, b);
    else if (ft_strcmp(operation, "pb"))
        push_b(a, b);
    else if (ft_strcmp(operation, "ra"))
        rotate_a(a);
    else if (ft_strcmp(operation, "rb"))
        rotate_b(b);
    else if (ft_strcmp(operation, "rr"))
        rotate_ab(a, b);
    else if (ft_strcmp(operation, "rra"))
        reverse_rotate_a(a);
    else if (ft_strcmp(operation, "rrb"))
        reverse_rotate_b(b);
    else if (ft_strcmp(operation, "rrr"))
        reverse_rotate_ab(a, b);
}

void execute_instructions(stack **a, stack **b)
{
    char *operation;

    while ((operation = get_next_line(0)))
    {
        execute_operation(a, b, operation);
        free(operation);
    }
    free(operation);    
}