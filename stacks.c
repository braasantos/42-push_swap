#include "push_swap.h"

void	ft_sort_3(t_node **lst)
{
	t_node	*biggest_nbr;
	
	biggest_nbr = find_max_node(*lst);
	if (biggest_nbr == *lst)
		ft_rotate_a(lst, 1);
	else if ((*lst)->next == biggest_nbr)
		ft_reverse_rotate_a(lst, 1);
	if ((*lst)->content >(*lst)->next->content)
		ft_swap_a(lst, 1);
}

void	ft_sort(t_node **lst, t_node **lstb)
{
	if (ft_lstsize(*lst) == 2)
		ft_swap_a(lst, 1);
	else if (ft_lstsize(*lst) == 3)
		ft_sort_3(lst);
	else
		ft_sort_final(lst, lstb);
}

int	ft_is_sorted(t_node *lst)
{
	if (!lst)
		return (1);
	while(lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_verify_create(t_node **lst, int ac, char **av)
{
	int	i;
	long	j;

	j = 0;
	if (ac < 2)
		ft_error();
	else
	{
		i = 1;
		while (av[i])
		{
			j = ft_atol(av[i]);
			if (j == 2147483649)
			{
				ft_free_stack(lst);
				ft_error();
			}
			ft_lstadd_back(lst, ft_newnode(j));
			i++;
		}
	}
}

void	ft_sort_final(t_node **lsta, t_node **lstb)
{
	int	len;

	len = ft_lstsize(*lsta);
	if (len-- > 3 && !ft_is_sorted(*lsta))
		ft_push_b(lsta, lstb, 1);
	if (len-- > 3 && !ft_is_sorted(*lsta))
		ft_push_b(lsta, lstb, 1);
	while (len-- > 3 && !ft_is_sorted(*lsta))
	{
		ft_inita(*lsta, *lstb);
		ft_a_para_b(lsta, lstb);
	}
	ft_sort_3(lsta);
	while (*lstb)
	{
		ft_initb(*lsta, *lstb);
		ft_b_para_a(lsta, lstb);
	}
	ft_currindex(*lsta);
	last_thing(lsta);
}
