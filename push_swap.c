/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:53:37 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/13 20:31:48 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	ft_verify_create(&a, ac, av);
	if (!a || ft_check_dup(a))
		ft_error(&a);
	if (!ft_is_sorted(a))
		ft_sort(&a, &b);
	ft_free_stack(a);
	return (0);
}
