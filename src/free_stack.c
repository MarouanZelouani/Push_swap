#include "../includes/push_swap.h"

static int ar_size(char **av)
{
    int len = 0;
    while (av[len])
        len++;
    return len;
}

void free_vector(char **av)
{
    int n;
    int size;

    n = 0;
    size = ar_size(av);
    while (n < size)
    {
        free(av[n]);
        n++;
    }
	free(av);
}

void free_stack (stack *head)
{
   stack* tmp;

    while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}
