#include "push_swap.h"

int is_all_digits(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = 0;
        if (av[i][0] == '-')
            j++;
        while(av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int exist_duplicates (char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            //printf("av[i]=%s AND av[j]=%s\n", av[i], av[j]);
            if (ft_strlen(av[i]) == ft_strlen(av[j]))
                if (ft_strncmp(av[i], av[j], ft_strlen(av[i])) == 0)
                    return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_sorted(stack *s)
{
    stack *current_node;
    
    current_node = s;
    if (s->next == NULL)
        return (1);
    while (current_node->next != NULL)
    {
        if (current_node->data > (current_node->next)->data)
            return (0);
        current_node = current_node->next;
    }
    return (1); 
}

// int is_all_integers(char **av)
// {
//     int i;
//     i = 0;
// }