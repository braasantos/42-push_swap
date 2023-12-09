/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:53:50 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 21:04:56 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_size(t_node *lst)
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

int	ft_getindex(t_node **lst, t_node *node)
{
	t_node	*current;
	int		idx;

	current = *lst;
	idx = 0;
	if (!node)
		return (-1);
	while (current)
	{
		if (current == node)
			return (idx);
		else
		{
			current->index = idx;
			current = current->next;
			idx++;
		}
	}
	return (-1);
}

void	ft_currindex(t_node *lst)
{
	int	idx;
	int	median;

	idx = 0;
	median = ft_size(lst) / 2;
	while (lst)
	{
		lst->index = idx;
		if (idx <= median)
			lst->above_median = 1;
		else
			lst->above_median = 0;
		lst = lst->next;
		++idx;
	}
}

void	ft_free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
