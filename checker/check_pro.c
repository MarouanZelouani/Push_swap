#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int main (int ac, char **args)
{
    stack *stack_a;
    stack *stack_b;
    int i;
    char **av;
    char *str;

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    str = NULL;
    // check if there is no arguments or the first arg id an empty string
    if (ac < 1 && args[1][0] == '\0')
        return (0);
    while (i < ac)
    {
        str = ft_strjoin(str, " ");
        str = ft_strjoin(str, args[i]);
        i++;
    }
    // spliting the args
    av = ft_split(str, ' ');
    // check if there is an error
    if(!is_all_digits(av) || !exist_duplicates(av))
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    // fetch the argument and create your stack
    init_stack(&stack_a, av);

    // execute the instructions
    execute_instructions(&stack_a, &stack_b);

    if(is_sorted(stack_a))
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    return (0);    
}
