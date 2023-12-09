/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:55:09 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 17:59:04 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*bro just a isdigit*/
int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || (c == '-' || c == '+'))
		return (1);
	return (0);
}

/*encontra o menor numero da lista e devolve ele*/
t_node	*find_min(t_node *lst)
{
	long	min;
	t_node	*current;

	if (!lst)
		return (NULL);
	min = LONG_MAX;
	while (lst)
	{
		if (lst->content < min)
		{
			min = lst->content;
			current = lst;
		}
		lst = lst->next;
	}
	return (current);
}

/*Funcao serve para adicionar um novo node 
 * e coloca o content (numero) para o node*/
/*adiciona o novo no criado para o fim da linked list*/
void	ft_lstadd(t_node **lst, t_node *new)
{
	t_node	*aux;

	aux = *lst;
	if (aux == NULL)
	{
		*lst = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}

int	ft_check_dup(t_node *a)
{
	t_node	*tmp;

	if (!a)
		return (0);
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

void	ft_error(t_node **lst)
{
	ft_free_stack(*lst);
	write(1, "Error\n", 6);
	exit(1);
}
