#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

static int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

static void execute_operation(stack **a, stack **b, char *operation)
{
    if (!ft_strcmp(operation, "sa\n"))
        swap_a(a, 0);
    else if (ft_strcmp(operation, "sb\n") == 0)
        swap_b(b, 0);
    else if (ft_strcmp(operation, "ss\n") == 0)
        swap_ab(a, b, 0);
    else if (ft_strcmp(operation, "pa\n") == 0)
        push_a(a, b, 0);
    else if (ft_strcmp(operation, "pb\n") == 0)
        push_b(a, b, 0);
    else if (ft_strcmp(operation, "ra\n") == 0)
        rotate_a(a, 0);
    else if (ft_strcmp(operation, "rb\n") == 0)
        rotate_b(b, 0);
    else if (ft_strcmp(operation, "rr\n") == 0)
        rotate_ab(a, b, 0);
    else if (ft_strcmp(operation, "rra\n") == 0)
        reverse_rotate_a(a, 0);
    else if (ft_strcmp(operation, "rrb\n") == 0)
        reverse_rotate_b(b, 0);
    else if (ft_strcmp(operation, "rrr\n") == 0)
        reverse_rotate_ab(a, b, 0);
    else {
        ft_putstr_fd("Error\n", 2);
        // FREE
        exit(1);
    }
}

void execute_instructions(stack **a, stack **b)
{
    char *op = get_next_line(0);
    while (op != NULL)
    {
        execute_operation(a, b, op);
        free(op);
        op = get_next_line(0);
    }
}