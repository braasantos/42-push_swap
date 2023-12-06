#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"


int ft_cheapest_nbr(t_node **lst)
{
    int i = 0;
    t_node *current;
    int cheapest_nbr;
    cheapest_nbr = INT_MAX;
    current = *lst;
    while (current)
    {
        if (current->push_cost < cheapest_nbr)
        {
            cheapest_nbr = current->push_cost;
            current->cheapest_nbr = current->content;
            current->cheapest_nbr_index = i;
        }
        i++;
        current = current->next;
    }
    return (cheapest_nbr);
}
int ft_abs(int a, int b)
{
    int c = (a - b);
    if (c < 0)
        c *= -1;
    return (c);
}
int find_max(t_node **lst)
{
    int max;
    if (!lst || !*lst)
        return (0);
    max = (*lst)->content;
    t_node *current = (*lst)->next;
    while(current)
    {
        if (current->content > max)
            max = current->content;
        current = current->next;
    }
    return (max);
}
t_node *find_max_node(t_node **lst)
{
    t_node *max;
    t_node *current;

    current= *lst;
    max = NULL;
    while (current)
    {
        if (max == NULL || current->content > max->content)
            max = current;
        current = current->next;
    }
    return max;
}

void target_utls(t_node *content, t_node **lstb)
{
    t_node *currenta;
    t_node *currentb;

    currenta = find_max_node(lstb);
    currentb = *lstb;
    printf("Max node of stack A %d\n", content->content);
    if (content->content == INT_MAX)
    {
            content = find_max_node(lstb);
            // content = find_max_node(lsta);
    }
}
void ft_check_target(t_node **lsta, t_node **lstb)
{
    t_node *currenta;
    t_node *currentb;
    int absdiff;
    currenta = *lsta;

    while (currenta)
    {
        currenta->target = malloc(sizeof(t_node));
        currenta->target->content = INT_MAX;
        currentb = *lstb;
        while (currentb)
        {
            absdiff = ft_abs(currenta->content, currentb->content);
            if (absdiff < ft_abs(currenta->content, currenta->target->content) && currentb->content < currenta->content)
            {
                currenta->target = currentb;
                currenta->target->index = ft_getindex(lstb, currentb);
            }
            currentb = currentb->next;
        }
        if (currenta->target->content == INT_MAX)
            target_utls(currenta, lstb);
        currenta = currenta->next;
    }
}
void ft_pushcost(t_node **lst)
{
    t_node *current;
    int index;
    if (!lst || !*lst)
        return ;
    current = *lst;
    index = 0;
    while (current)
    {
        current->index = index;
        if (current->index <= (ft_lstsize(*lst) / 2))
            current->push_cost = current->index;
        else 
            current->push_cost = (ft_lstsize(*lst) - current->index); 
        current = current->next;
        index++;
    }    
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
void ft_sort_3(t_node **lst)
{
    int a = (*lst)->content;
    int b = (*lst)->next->content;
    int c = (*lst)->next->next->content;

    if (a > b && c > a)
        ft_swap_a(lst, 1);
    else if (a > b && b > c)
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
    else if (a > b && c > b)
        ft_rotate_a(lst, 1);

}
void ft_inita(t_node **lsta, t_node **lstb)
{
    t_node *curr = *lsta;
    ft_check_target(lsta, lstb);
    ft_pushcost(lsta);
    ft_cheapest_nbr(lsta);
    printf("%d\n", curr->cheapest_nbr_index);
    printf("%d\n", curr->cheapest_nbr);
    while (curr)
    {
        printf("node %d: target index: %d\n", curr->content, curr->target->content);
        curr = curr->next;
    }
}
void ft_initb(t_node **lsta, t_node **lstb)
{
    ft_check_target(lstb, lsta);
    ft_pushcost(lstb);
    ft_cheapest_nbr(lstb);
    t_node *curr = *lstb;
    printf("%d\n", curr->cheapest_nbr_index);
    printf("%d\n", curr->cheapest_nbr);
    printf("node %d: target index: %d\n", curr->content, curr->target->content);
}
void ft_pass_a(t_node **lsta, t_node **lstb)
{
    t_node *curra;
    t_node *currb;
    curra = *lsta;
    currb = *lstb;

    // while (curra)
    // {
        ft_inita(lsta, lstb);
        // // if (curra->target != NULL && curra->target->index > 0)
        // // {
        // //     ft_swap_b(lstb, 1);
        // //     ft_push_b(lsta, lstb, 1);
        // // }
        // if (curra->target->index >= (ft_lstsize(*lstb) / 2))
        //     ft_rotate_b(lstb, 1);
        // else
        //      ft_push_b(lsta, lstb, 1);
    //     curra = curra->next;
    // }
}
void ft_sort_final(t_node **lsta, t_node **lstb)
{
    while (ft_lstsize(*lsta) > 3 && ft_lstsize(*lstb) < 2)
            ft_push_b(lsta, lstb, 1);
    if (ft_lstsize(*lsta) == 3)
        ft_sort_3(lsta);
    if (!ft_is_sorted(lsta))
        ft_pass_a(lsta, lstb);
}
/*ve o tamanho da lista para realizar as operacoes*/
void ft_sort(t_node **lst)
{
    t_stack *b = (t_stack *)malloc(sizeof(t_stack));
    b->top = NULL;
    if (ft_lstsize(*lst) == 2)
    {
        ft_swap_a(lst, 1);
        ft_free_stack(b);
    }
    else if (ft_lstsize(*lst) == 3)
    {
        ft_sort_3(lst);
        ft_free_stack(b);
    }
    else
        ft_sort_final(lst, &b->top);
    t_node *current = b->top;
    printf("stack b\n");
    while (current) {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
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
    t_node *current = a->top;
    while (current) {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
    ft_free_stack(a);
    return (0);
}
