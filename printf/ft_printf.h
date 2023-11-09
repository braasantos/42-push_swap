/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:07:46 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/10/16 17:20:54 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//HEADERS
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

// FUNCTIONS
int			ft_printf(const char *format, ...);
void		ft_put_char(int c, int *count);
void		ft_put_str(char *str, int *count);
void		ft_put_nbr(int nbr, int *count);
void		ft_putadress(size_t nbr, int *count);
void		ft_puthexa(unsigned int nbr, const char *format, int *count);
void		ft_putunsig(unsigned int n, int *count);

#endif
