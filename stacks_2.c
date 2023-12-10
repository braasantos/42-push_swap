/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braasantos <braasantos@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:03:03 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/10 08:47:47 by braasantos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_para_b(t_node **lsta, t_node **lstb)
{
	t_node	*curr;

	curr = ft_get_cheapest(*lsta);
	if (curr->above_median && curr->target->above_median)
		ft_r_a_b(lsta, lstb, curr);
	else if (!(curr->above_median) && !(curr->target->above_median))
		ft_rev_rotate_a_b(lsta, lstb, curr);
	ft_push(lsta, curr, 'a');
	ft_push(lstb, curr->target, 'b');
	ft_push_b(lsta, lstb, 1);
}

/*ve os targets da stack a em a e manda os nodes de a0 para b*/
void	ft_b_para_a(t_node **lsta, t_node **lstb)
{
	ft_push(lsta, (*lstb)->target, 'a');
	ft_push_a(lstb, lsta, 1);
}

/*inicia tudo da stack a com o targets de a e o push cost e o cheapest*/
void	ft_inita(t_node *lsta, t_node *lstb)
{
	ft_currindex(lsta);
	ft_currindex(lstb);
	ft_check_target_a(lsta, lstb);
	ft_pushcost(lsta, lstb);
	ft_cheapest_nbr(lsta);
}

/*inicia tudo da stack b com o targets de b e o push cost e o cheapest*/
void	ft_initb(t_node *lsta, t_node *lstb)
{
	ft_currindex(lsta);
	ft_currindex(lstb);
	ft_check_target_b(lsta, lstb);
}

t_node	*ft_get_cheapest(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->cheapest_nbr == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
