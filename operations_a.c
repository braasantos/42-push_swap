/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:03:19 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 09:32:50 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_node **lst, int flg)
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
	if (flg)
		write(1, "sa\n", 3);
}

void	ft_ss(t_node **lsta, t_node **lstb, int flg)
{
	ft_swap_a(lsta, 0);
	ft_swap_b(lstb, 0);
	if (flg == 1)
		write(1, "ss\n", 3);
}

void	ft_push_a(t_node **b, t_node **a, int flg)
{
	t_node	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (flg)
		write(1, "pa\n", 3);
}

void	ft_rr(t_node **lsta, t_node **lstb, int flg)
{
	ft_rotate_a(lsta, 0);
	ft_rotate_b(lstb, 0);
	if (flg)
		write(1, "rr\n", 3);
}

void	ft_reverse_rotate_a(t_node **lst, int flg)
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
		write(1, "rra\n", 4);
}
