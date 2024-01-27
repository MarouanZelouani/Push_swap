#include "../includes/push_swap.h"


int find_index_in_b (stack *b, int data)
{
    int		index;
	t_stack	*tmp;

	index = 1;
	if (data > stack_b->nbr && data < ft_lstlast(stack_b)->data)
		index = 0;
	else if (data > ft_max(b) || data < ft_min(b))
		index = ft_find_index(b, ft_max(b));
	else
	{
		tmp = b->next;
		while (b->data < data || tmp->data > data)
		{
			b = b->next;
			tmp = b->next;
			index++;
		}
	}
	return (index);
}
