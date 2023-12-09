/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:02:35 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 09:02:48 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node *lst)
{
	long	max;
	t_node	*current;

	if (!lst)
		return (NULL);
	max = LONG_MIN;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
			current = lst;
		}
		lst = lst->next;
	}
	return (current);
}

void	ft_r_a_b(t_node **lsta, t_node **lstb, t_node *node)
{
	while (*lstb != node->target && *lsta != node)
		ft_rr(lsta, lstb, 1);
	ft_currindex(*lsta);
	ft_currindex(*lsta);
}
