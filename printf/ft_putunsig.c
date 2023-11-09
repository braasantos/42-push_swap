/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:21:10 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/16 17:22:11 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsig(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunsig(n / 10, count);
		n = n % 10;
	}
	if (n < 10)
	{
		n += 48;
		*count += write(1, &n, 1);
	}
}
