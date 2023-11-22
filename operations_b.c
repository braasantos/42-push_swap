void ft_swap_b(t_node **lst, int flg)
{
    t_node *first;
    t_node *second;
    int temp;
    if (!lst || !*lst || !(*lst)->next)
        return ;
    first = *lst;
    second = (*lst)->next;
    temp = first->content;
    first->content = second->content;
    second->content = temp;
    *lst = first;
    (*lst)->next = second;
    if (flg == 1)
        write(1, "sa\n", 3);
}
void ft_push_b(t_node **a, t_node **b, int flg)
{
    t_node *tmp;
    if (!(*a))
        return ;
    tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        *b = tmp;
    if (flg)
        write(1, "pb\n", 3);
    t_node *current = *b;
    printf("STACK B\n");
    while (current)
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
}
void ft_rotate_b(t_node **lst, int flg)
{
    if (!(*lst) || !lst || !(*lst)->next)
        return ;
    t_node *tmp = *lst;
    t_node *first = *lst;
    *lst = (*lst)->next;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = ft_newnode(first->content);
    if (flg)
        write(1, "ra\n", 3);
    t_node *current = *lst;
    while (current)
    {
        printf("%d ", current->content);
        current = current->next;
    }
}
void ft_reverse_rotate_b(t_node **lst, int flg)
{
    if (!(*lst) || !lst || !(*lst)->next)
        return ;
    t_node *tmp = *lst;
    t_node *secodLast = NULL;
    while (tmp->next != NULL)
    {
        secodLast = tmp;
        tmp = tmp->next;
    }
    tmp->next = *lst;
    *lst = tmp;

    secodLast->next = NULL;
    if (flg)
        write(1, "rra\n", 4);
    t_node *current = *lst;
    while (current)
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
}