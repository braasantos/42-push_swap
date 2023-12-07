#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

void last_thing(t_node **lst)
{
    t_node *curr;
    curr = find_min(lst);
    while((*lst)->content != curr->content)
    {
        if (curr->above_median)
            ft_rotate_a(lst, 1);
        else 
            ft_reverse_rotate_a(lst, 1);
    }
}
int ft_cheapest_nbr(t_node **lst)
{
    t_node *current;
    t_node *cheapest_node;

    current = *lst;
    cheapest_node = NULL;
    while (current)
    {
        if (cheapest_node == NULL || current->push_cost < cheapest_node->push_cost)
        {
            cheapest_node = current;
        }

        current = current->next;
    }
    if (cheapest_node != NULL)
        return cheapest_node->content;
    else
        return INT_MAX;
}


t_node *ft_get_cheapest(t_node **lst)
{
	if (!lst || !(*lst))
		return (NULL);
	t_node *current = *lst;

	while (current)
	{
		if (current->cheapest_nbr)
			return (current);
		current = current->next;
	}
	return (NULL);
}
int ft_abs(int a, int b)
{
    int c = (a - b);
    if (c < 0)
        c *= -1;
    return (c);
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
void target_utls_a(t_node *content, t_node **lstb, t_node **lsta, char c)
{
    if (c == 'a')
        content->target = find_max_node(lstb);
    else 
        content->target = find_max_node(lsta);
}
void target_utls_b(t_node *content, t_node **lstb, t_node **lsta, char c)
{
    if (c == 'b')
        content->target = find_max_node(lsta);
    else 
        content->target = find_max_node(lstb);
}
void ft_check_target_a(t_node **lsta, t_node **lstb, char c)
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
            target_utls_a(currenta, lstb, lsta, c);
        currenta = currenta->next;
    }
}
void ft_check_target_b(t_node **lsta, t_node **lstb, char c)
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
            if (absdiff < ft_abs(currenta->content, currenta->target->content) && currentb->content > currenta->content)
            {
                currenta->target = currentb;
                currenta->target->index = ft_getindex(lstb, currentb);
            }
            currentb = currentb->next;
        }
        if (currenta->target->content == INT_MAX)
            target_utls_b(currenta, lstb, lsta, c);
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
/*inicia tudo da stack a com o targets de a e o push cost e o cheapest*/
void ft_inita(t_node **lsta, t_node **lstb)
{
    // t_node *curr = *lsta;
    ft_check_target_a(lsta, lstb, 'a');
    ft_pushcost(lsta);
    ft_cheapest_nbr(lsta);
    ft_median(lsta);
//     while (curr)
//     {
//         printf("node %d: target: %d\n", curr->content, curr->target->content);
//         printf("node %d: target index: %d\n", curr->content, curr->target->index);
//         curr = curr->next;
//     }
}
/*inicia tudo da stack b com o targets de b e o push cost e o cheapest*/
void ft_initb(t_node **lsta, t_node **lstb)
{
    // t_node *curr = *lstb;
    ft_check_target_b(lstb, lsta, 'b');
    ft_pushcost(lstb);
    printf("im here\n");
    ft_cheapest_nbr(lstb);
    ft_median(lstb);
    // printf("%d\n", curr->cheapest_nbr_index);
    // printf("%d\n", curr->cheapest_nbr);
    // while (curr)
    // {
    //     printf("node %d: target: %d\n", curr->content, curr->target->content);
    //     printf("node %d: target index: %d\n", curr->content, curr->target->index);
    //     curr = curr->next;
    // }
}
void prep_for_push(t_node **lst, t_node *node, char c)
{
    t_node *curr;

    curr = *lst;
    while (curr != node)
    {
        if (c == 'a')
        {
            if (node->above_median)
                ft_rotate_a(lst, 1);
            else 
                ft_reverse_rotate_a(lst, 1);
        }
        else if (c == 'b')
        {
            if (node->above_median)
                ft_rotate_b(lst, 1);
            else 
                ft_reverse_rotate_b(lst, 1);   
        }
        curr = *lst;
    }
}

void ft_rev_rotate_a_b(t_node **lsta, t_node **lstb, t_node *node)
{
    while ((*lstb) != node->target && (*lsta) != node)
    {
        ft_rrr(lsta, lstb, 1);
        ft_inita(lsta, lstb);
        ft_initb(lsta, lstb);
    }
}
/*ve os targets da stack a em a e manda os nodes de a0 para b*/
void ft_b_para_a(t_node **lsta, t_node **lstb)
{
    t_node *curr;
    curr = *lstb;
    prep_for_push(lsta, curr->target, 'a');
    ft_push_a(lstb, lsta, 1);
}
void ft_r_a_b(t_node **lsta, t_node **lstb, t_node *node)
{
    t_node *currb;
    t_node *curra;

    currb = *lstb;
    curra = *lsta;
    while (currb != node->target && curra != node)
        ft_rr(lsta, lstb, 1);
    ft_median(lsta);
    ft_median(lstb);
}
/*ve os targets da stack a em a e manda os nodes de a para b*/
void ft_a_para_b(t_node **lsta, t_node **lstb)
{
    t_node *curr;

    curr = ft_get_cheapest(lsta);
    if (curr->above_median && curr->target->above_median)
            ft_r_a_b(lsta, lstb, curr);
    else if (!(curr->above_median) && !(curr->target->above_median))
            ft_rev_rotate_a_b(lsta, lstb, curr);
    prep_for_push(lsta, curr, 'a');
    prep_for_push(lsta, curr->target, 'b');
    ft_push_b(lstb, lsta, 1);
}
void ft_sort_final(t_node **lsta, t_node **lstb)
{
    while (ft_lstsize(*lsta) > 3 && ft_lstsize(*lstb) < 2)
    {
        ft_push_b(lsta, lstb, 1);
    }
    while (ft_lstsize(*lsta) > 3 && !ft_is_sorted(lsta))
    {
        ft_inita(lsta, lstb);
        ft_a_para_b(lsta, lstb);
    }
    ft_sort_3(lsta);
    while (*lstb)
    {
        ft_initb(lsta, lstb);
        ft_b_para_a(lsta, lstb);
    }
    ft_median(lsta);
    last_thing(lsta);
}
void ft_sort(t_node **lst)
{
     t_stack *b;

    b = (t_stack *)malloc(sizeof(t_stack));
    b->top = NULL;
    if (ft_lstsize(*lst) == 2)
    {
        ft_swap_a(lst, 1);
        ft_free_stack(b);
        b = NULL;
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
    while (current)
    {
        printf("%d ", current->content);
        current = current->next;
    }
    printf("\n");
}
/*again just the regular atoi*/
long	ft_atol(const char *nptr)
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
            j = ft_atol(av[i]);
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
