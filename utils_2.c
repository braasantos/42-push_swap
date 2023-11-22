/*bro just a isdigit*/
int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57 )|| (c == '-' || c == '+'))
	{
		return (1);
	}
	return (0);
}
/*encontra o menor numero da lista e devolve ele*/
int find_min(t_node **lst)
{
    int min;
    if (!lst || !*lst)
        return (0);
    min = (*lst)->content;
    t_node *current = (*lst)->next;
    while(current)
    {
        if (current->content < min)
            min = current->content;
        current = current->next;
    }
    return (min);
}
/*Funcao serve para adicionar um novo node e coloca o content (numero) para o node*/
/*adiciona o novo no criado para o fim da linked list*/
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*aux;

	aux = *lst;
	if (aux == NULL)
	{
		*lst = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}

int ft_check_dup(t_node *a)
{
    t_node *tmp;
    while(a)
    {
        tmp = a->next;
        while (tmp)
        {
            if (a->content == tmp->content)
                return (1);
            tmp = tmp->next;
        }
        a = a->next;
    }
    return (0);
}