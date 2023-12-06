#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

t_node	*ft_newnode(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
int ft_getindex(t_node **lst, t_node *node)
{
    t_node *current;
    int idx;
    
    current = *lst;
    idx = 0;
    if (!node)
        return -1;
    while (current)
    {
        if (current == node)
            return (idx);
        else 
        {
            current = current->next;
            idx++;
        }
    }
    return (idx);
}
void ft_free_stack(t_stack *stack)
{
    if (!stack)
        return;
    t_node *current;
    t_node *next;

    current = stack->top;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
void ft_error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}