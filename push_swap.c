#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"
void ft_reverse_rotate_a(t_node **lst, int flg)
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
void ft_rotate_a(t_node **lst, int flg)
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
     printf("\n");
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
void ft_swap_a(t_node **lst, int flg)
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
    t_node *current = *lst;
    while (current)
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
    if (flg)
        write(1, "sa\n", 3);
}
void ft_sort_2(t_node **lst)
{
    if (ft_getindex(lst) > 0)
        ft_swap_a(lst, 1);
}
void ft_sort_3(t_node **lst)
{
    int a = (*lst)->content;
    int b = (*lst)->next->content;
    int c = (*lst)->next->next->content;

    if (a > b && c > a) // certa
        ft_swap_a(lst, 1);
    else if (a > b && b > c) // certo
    {
        ft_swap_a(lst, 1);
        ft_reverse_rotate_a(lst, 1);
    }
    else if (b > a && a > c)
        ft_reverse_rotate_a(lst, 1);
    else if (b > c && c > a)
    {
        ft_swap_a(lst, 1);
        ft_rotate_a(lst, 1);
    }
    else if (a > b && c > b) // certa
        ft_rotate_a(lst, 1);

}

/*ve o tamanho da lista para realizar as operacoes*/
void ft_sort(t_node **lst)
{
    t_stack *b = (t_stack *)malloc(sizeof(t_stack));
    b->top = NULL;
    if (ft_lstsize(*lst) <= 3)
    {
        if (ft_lstsize(*lst) == 2)
            ft_sort_2(lst);
        else
            ft_sort_3(lst);
        ft_free_stack(b);
    }
    // else// ft_push_b(lst, &b->top, 1);
    // {
    //     ft_reverse_rotate_a(lst, 1);
    //     ft_rotate_a(lst, 1);
    // }
    //else if (ft_lstsize(*lst) >= 10 && ft_lstsize(*lst) <= 100)
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
/*bro just a isdigit*/
int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57 )|| (c == '-' || c == '+'))
	{
		return (1);
	}
	return (0);
}
/*again just the regular atoi*/
long	ft_atoi(const char *nptr)
{
	int	sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
    if (*nptr == '\0')
		return (2147483649);
	while (*nptr)
	{
        if (!ft_isdigit(*nptr))
			return (2147483649);
		num = num * 10 + *nptr - 48;
		nptr++;
	}
    if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		return (2147483649);
	return (num * sign);
}
void ft_error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}
t_stack *ft_verify_create(int ac, char **av)
{
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    int i = 1;
    long j = 0;
    a->top = NULL;
    if (ac < 2)
            ft_error();
    else
    {
        while (i < ac)
        {
            j = ft_atoi(av[i]);
            if (j == 2147483649)
            {
                ft_free_stack(a);
                ft_error();
            }
             ft_lstadd_back(&a->top, ft_newnode(j));
            i++;
        }
    }
    t_node *current = a->top;
    while (current) {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
    find_min(&a->top);
    return (a);
}
int ft_is_sorted(t_node **lst)
{
    int min;
    if (!lst || !*lst)
        return (1);
    min = (*lst)->content;
    t_node *current = (*lst)->next;
    while(current)
    {
        if (current->content < min)
            return (0);
        min = current->content;
        current = current->next;
    }
    return (1);
}
int main(int ac, char **av)
{
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    a->top = NULL;
    if (ac == 1) 
        return (0);
    a = ft_verify_create(ac, av);
    if (!a || ft_check_dup(a->top))
    {
        ft_free_stack(a);
        ft_error();
    }
    if (!ft_is_sorted(&a->top))
        ft_sort(&a->top);
    // t_node *current = a->top;
    // while (current) {
    //     printf("%d ", current->content);
    //     current = current->next;
    // }
    // printf("\n");
    ft_free_stack(a);
    return (0);
}
