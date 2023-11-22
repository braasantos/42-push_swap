#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h> 
# include <string.h>
# include <stdlib.h>
# include <limits.h>

// Node struct
typedef struct s_node
{
  	int					content;
	int					index;
	struct s_node			*next;
	struct s_node           *prev;	
}               t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

/*OPERATIONS*/
void ft_swap_a(t_node **lst, int flg);
void ft_swap_b(t_node **lst, int flg);
void ft_ss(t_node **lsta, t_node **lstb, int flg);
void ft_push_a(t_node **b, t_node **a, int flg);
void ft_push_b(t_node **a, t_node **b, int flg);
void ft_rotate_a(t_node **lst, int flg);
void ft_rotate_b(t_node **lst, int flg);
void ft_rr(t_node **lsta, t_node **lstb, int flg);
void ft_reverse_rotate_a(t_node **lst, int flg);
void ft_reverse_rotate_a(t_node **lst, int flg);
void ft_rrr(t_node **lsta, t_node **lstb, int flg);
/*UTILS*/
t_node	*ft_newnode(int content);
int	ft_lstsize(t_node *lst);
int ft_getindex(t_node **lst);
void ft_free_stack(t_stack *stack);
int ft_check_dup(t_node *a);
void	ft_lstadd_back(t_node **lst, t_node *new);
int find_min(t_node **lst);
int	ft_isdigit(int c);
long	ft_atoi(const char *nptr);
t_stack *ft_verify_create(int ac, char **av);
/*SORT*/
void ft_sort(t_node **lst);
int ft_is_sorted(t_node **lst);
/*ERROR*/
void ft_error(void);
/*ALGORITHIM*/
#endif