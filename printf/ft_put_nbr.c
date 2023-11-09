/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:18:37 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/16 17:23:01 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_nbr(int nbr, int *count)
{
	if (nbr == -2147483648)
	{
		*count += write(1, "-2147483648", 11);
	}
	else 
	{
		if (nbr < 0)
		{
			ft_put_char('-', count);
			nbr = -nbr;
		}
		if (nbr >= 10)
			ft_put_nbr(nbr / 10, count);
		ft_put_char(nbr % 10 + '0', count);
	}
}
