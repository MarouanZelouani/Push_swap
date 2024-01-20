#include "../includes/push_swap.h"

// static int	free_all(char **str, int word)
// {
// 	while (word)
// 		free(str[word--]);
// 	free(str);
// 	return (0);
// }
static int ar_size(char **av)
{
    int len = 0;
    while (av[len])
        len++;
    return len;
}

static void free_stack (stack *head)
{
   stack* tmp;

    while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

//parse the agrument using str join (its super easy)
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
    free(str);
    // check if there is an error
    if(!is_all_digits(av) || !exist_duplicates(av))
    {
        //printf("error2");
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    // fetch the argument and create your stack
    init_stack(&stack_a, av);
    // free
    //free_all(av,  ac - 1);

    // CREATE A FUNCTION TO DO THIS
    int n = 0;
    int size = ar_size(av);
    while (n < size)
    {
        free(av[n]);
        n++;
    }
	free(av);
    //free_all(args, ac - 1);
    // check is the stack is already sorted
    if(is_sorted(stack_a))
        return (0);
    // sorting stack 

    // CHECK IS A PROBLEM HAPPEND WHILE INIT THE STACK
    
    sort_stack(&stack_a, &stack_b);
    free_stack (stack_a);
    return (0);
}