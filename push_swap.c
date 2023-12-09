/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:53:37 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 20:58:42 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_split(char **av)
{
    int i = 0;
    while (av[i])
    {
        free(av[i]);
        i++;
    }
    free(av);
}
int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	ft_verify_create(&a, ac, av);
	if (!a || ft_check_dup(a))
		ft_error(&a);
	if (!ft_is_sorted(a))
		ft_sort(&a, &b);
	if (ac == 2)
		ft_free_split(av);
	ft_free_stack(a);
	return (0);
}
