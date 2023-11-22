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
/*atualiza a lista com o index do menor numero*/
int ft_getindex(t_node **lst)
{
    int min;
    int idx = 0;
    int idmin = 0;
    if (!lst || !*lst)
        return (0);
    min = (*lst)->content;
    t_node *current = (*lst)->next;
    while(current)
    {
        idx++;
        if (current->content < min)
        {
            min = current->content;
            idmin = idx;
        }
        current = current->next;
    }
    (*lst)->index = idx;
    return (idmin);
}
void ft_free_stack(t_stack *stack)
{
    if (!stack)
        return;

    t_node *current = stack->top;
    t_node *next;
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