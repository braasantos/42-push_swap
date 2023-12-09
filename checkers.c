/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:05:21 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 20:52:14 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_target_a(t_node *lsta, t_node *lstb)
{
	t_node	*currentb;
	t_node	*target_node;
	long	match;

	while (lsta)
	{
		match = LONG_MIN;
		currentb = lstb;
		while (currentb)
		{
			if (currentb->content < lsta->content && currentb->content > match)
			{
				match = currentb->content;
				target_node = currentb;
			}
			currentb = currentb->next;
		}
		if (match == LONG_MIN)
			lsta->target = find_max_node(lstb);
		else
			lsta->target = target_node;
		lsta = lsta->next;
	}
}

void	ft_check_target_b(t_node *lsta, t_node *lstb)
{
	t_node	*currenta;
	t_node	*target_node;
	long	match;

	while (lstb)
	{
		match = LONG_MAX;
		currenta = lsta;
		while (currenta)
		{
			if (currenta->content > lstb->content && currenta->content < match)
			{
				match = currenta->content;
				target_node = currenta;
			}
			currenta = currenta->next;
		}
		if (match == LONG_MAX)
			lstb->target = find_min(lsta);
		else
			lstb->target = target_node;
		lstb = lstb->next;
	}
}

void	ft_pushcost(t_node *lsta, t_node *lstb)
{
	int		len_a;
	int		len_b;

	len_a = ft_size(lsta);
	len_b = ft_size(lstb);
	while (lsta)
	{
		lsta->push_cost = lsta->index;
		if (!(lsta->above_median))
			lsta->push_cost = len_a - (lsta->index);
		if (lsta->target->above_median)
			lsta->push_cost += lsta->target->index; 
		else 
			lsta->push_cost += len_b - (lsta->target->index);
		lsta = lsta->next;
	}
}

void	ft_push(t_node **lst, t_node *node, char stack)
{
	while ((*lst) != node)
	{
		if (stack == 'a')
		{
			if (node->above_median)
				ft_rotate_a(lst, 1);
			else
				ft_reverse_rotate_a(lst, 1);
		}
		else if (stack == 'b')
		{
			if (node->above_median)
				ft_rotate_b(lst, 1);
			else 
				ft_reverse_rotate_b(lst, 1);
		}
	}
}

void	last_thing(t_node **lsta)
{
	while ((*lsta)->content != find_min(*lsta)->content)
	{
		if (find_min(*lsta)->above_median)
			ft_rotate_a(lsta, 1);
		else
			ft_reverse_rotate_a(lsta, 1);
	}
}
