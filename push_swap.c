#include "push_swap.h"


//parse the agrument using str join (its super easy)
int main (int ac, char **av)
{
    stack *stack_a;
    stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    // check if there is no arguments or the first arg id an empty string
    if (ac < 1 && av[1][0] == '\0')
        return (0);
    // check if there is an error
    if(!is_all_digits(av) || !exist_duplicates(av))
    {
        //printf("error2");
        ft_putstr_fd("ERROR\n", 2);
        return (0);
    }
    // fetch the argument and create your stack
    init_stack(&stack_a, av);
    // check is the stack is already sorted
    if(is_sorted(stack_a))
    {
        ft_putstr_fd("SORTED\n", 2);
        return (0);
    }

    // printing the stack a
    printf("not sorted\n");
    print_stack(stack_a);

    printf("======================\n");

    // sorting stack 
    sort_stack(&stack_a, &stack_b);

    // testing the stort operations
    printf("======================\n");
    printf("sorted\n");
    print_stack(stack_a);

    printf("======================\n");
    if(is_sorted(stack_a))
    {
        ft_putstr_fd("SORTED\n", 1);
        return (0);
    }

    // if (ft_stack_size(stack_a) == 3)
    //     sort_three(&stack_a);
    // else 
    //     printf("else");
    // //swap_a(&stack_a);
    // //rotate_a(&stack_a);
    // //reverse_rotate_a(&stack_a);
    // push_b(&stack_a, &stack_b);
    // printf("======================\n");
    // printf("stack b\n");
    // print_stack(stack_b);
    // printf("======================\n");
    return (0);
}