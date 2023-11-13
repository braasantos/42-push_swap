#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
    new->content =malloc(sizeof(int));
    if (!new->content)
      return (NULL);
	 *((int*)(new->content)) =  content;
	new->next = NULL;
	return (new);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
		{
			sign = -1;
		}
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + nptr[i] - 48;
		i++;
	}
	return (num * sign);
}

// int main(int ac, char **av)
// {
//   (void)ac;
//   int nbr = ft_atoi(av[1]);
//   while (nbr > 0)
//   {
//     t_list *new_node = ft_lstnew(nbr);
//   }
  
// }

void add_to_lst(int ac, char **str)
{
    t_list *head = NULL;
    t_list *current = NULL;
    int i = 1;
    int num;
    while (i < ac)
    {
        num = ft_atoi(str[i]);
        t_list *new_node = ft_lstnew(num);
        if (!new_node)
            return;
        if (!head)
        {
            head = new_node;
            current = head;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        i++;
    }
    current = head;
    while (current) {
        printf("%d ", *((int*)(current->content)));
        current = current->next;
    }
    printf("\n");
    current = head;
}

int main(int ac, char **av)
{
    int i = 1;
    int j;
    int num;
    if (ac < 2) 
        return (0);
    while (av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if(!ft_isdigit(av[i][j]))
            {
                write(1, "Error\n", 6);
                return (0);
            }
            j++;
        }
        i++;
    }
    i = 1;
    j = 0;
    add_to_lst(ac, av);
}
