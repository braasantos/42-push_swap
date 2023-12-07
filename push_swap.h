#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h> 
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

// Node struct
typedef struct s_node
{
  	int						content;
	int						index;
	int						push_cost;
	bool					above_median;
	struct s_node			*target;
	int						cheapest_nbr;
	int						cheapest_nbr_index;
	struct s_node			*next;
	struct s_node			*prev;
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
void ft_reverse_rotate_b(t_node **lst, int flg);
void ft_rrr(t_node **lsta, t_node **lstb, int flg);
/*UTILS*/
t_node	*ft_newnode(int content);
int	ft_lstsize(t_node *lst);
int ft_getindex(t_node **lst, t_node *node);
void ft_free_stack(t_stack *stack);
void ft_median(t_node **lst);
int ft_check_dup(t_node *a);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node *find_min(t_node **lst);
t_node *find_max_node(t_node **lst);
void last_thing(t_node **lst);
void last_thing(t_node **lst);
int	ft_isdigit(int c);
void prep_for_push(t_node **lst, t_node *node, char c);
void ft_a_para_b(t_node **lsta, t_node **lstb);
void ft_rr_a_b(t_node **lsta, t_node **lstb, t_node *node);
void ft_b_para_a(t_node **lsta, t_node **lstb);
long	ft_atoi(const char *nptr);
t_stack *ft_verify_create(int ac, char **av);
void ft_median(t_node **lst);
/*SORT*/
void ft_sort(t_node **lst);
int ft_is_sorted(t_node **lst);
/*ERROR*/
void ft_error(void);
/*ALGORITHIM*/
#endif