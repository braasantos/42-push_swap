#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

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
    if (flg)
        write(1, "sa\n", 3);
}
void ft_ss(t_node **lsta, t_node **lstb, int flg)
{
    ft_swap_a(lsta, 0);
    ft_swap_b(lstb, 0);
    if (flg == 1)
        write(1, "ss\n", 3);
}
void ft_push_a(t_node **b, t_node **a, int flg)
{
    t_node *tmp;

    if (!(*b))
        return ;
    tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
    if (flg)
        write(1, "pa\n", 3);
}
void ft_rr(t_node **lsta, t_node **lstb, int flg)
{
    ft_rotate_a(lsta, 0);
    ft_rotate_b(lstb, 0);
    if (flg)
        write(1, "rr\n", 1);
}
void ft_reverse_rotate_a(t_node **lst, int flg)
{
    if (!(*lst) || !lst || !(*lst)->next)
        return ;
    t_node *tmp;
    t_node *secodLast;
    
    tmp = *lst;
    secodLast = NULL;
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
}
void ft_rrr(t_node **lsta, t_node **lstb, int flg)
{
    ft_reverse_rotate_a(lsta, 0);
    ft_reverse_rotate_b(lstb, 0);
    if (flg)
        write(1, "rrr\n", 4);
}