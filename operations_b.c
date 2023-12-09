/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:50:18 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 09:28:15 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_node **lst, int flg)
{
	t_node	*first;
	t_node	*second;
	int		temp;

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
		write(1, "sb\n", 3);
}

void	ft_push_b(t_node **a, t_node **b, int flg)
{
	t_node	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (flg)
		write(1, "pb\n", 3);
}

void	ft_rotate_b(t_node **lst, int flg)
{
	t_node	*tmp;
	t_node	*first;

	if (!(*lst) || !lst || !(*lst)->next)
		return ;
	tmp = *lst;
	first = *lst;
	*lst = (*lst)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_newnode(first->content);
	if (flg)
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate_b(t_node **lst, int flg)
{
	t_node	*tmp;
	t_node	*second_last;

	if (!(*lst) || !lst || !(*lst)->next)
		return ;
	tmp = *lst;
	second_last = NULL;
	while (tmp->next != NULL)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	tmp->next = *lst;
	*lst = tmp;
	second_last->next = NULL;
	if (flg)
		write(1, "rrb\n", 4);
}
