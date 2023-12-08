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
	{
		ft_free_stack(&a);
		ft_error();
	}
	if (!ft_is_sorted(a))
		ft_sort(&a, &b);
	while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");
	ft_free_stack(&a);
	return (0);
}
