/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:58:20 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 09:30:02 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_a_b(t_node **lsta, t_node **lstb, t_node *node)
{
	while ((*lstb) != node->target && (*lsta) != node)
		ft_rrr(lsta, lstb, 1);
	ft_currindex(*lsta);
	ft_currindex(*lstb);
}

void	ft_rotate_a(t_node **lst, int flg)
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
		write(1, "ra\n", 3);
}

void	ft_rrr(t_node **lsta, t_node **lstb, int flg)
{
	ft_reverse_rotate_a(lsta, 0);
	ft_reverse_rotate_b(lstb, 0);
	if (flg)
		write(1, "rrr\n", 4);
}

void	ft_cheapest_nbr(t_node *lst)
{
	t_node	*cheapest_node;
	long	cheapest_value;

	if (!lst)
		return ;
	cheapest_value = LONG_MAX;
	while (lst)
	{
		if (lst->push_cost < cheapest_value)
		{
			cheapest_value = lst->push_cost;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	cheapest_node->cheapest_nbr = 1;
}

long	ft_atol(const char *nptr)
{
	int		sign;
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
