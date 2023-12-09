/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjorge-m <bjorge-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:00:46 by bjorge-m          #+#    #+#             */
/*   Updated: 2023/12/09 10:27:30 by bjorge-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int						cheapest_nbr;
	bool					above_median;
	struct s_node			*target;
	struct s_node			*next;
	struct s_node			*prev;
}		t_node;

/*OPERATIONS*/
void	ft_swap_a(t_node **lst, int flg);
void	ft_swap_b(t_node **lst, int flg);
void	ft_ss(t_node **lsta, t_node **lstb, int flg);
void	ft_push_a(t_node **b, t_node **a, int flg);
void	ft_push_b(t_node **a, t_node **b, int flg);
void	ft_rotate_a(t_node **lst, int flg);
void	ft_rotate_b(t_node **lst, int flg);
void	ft_rr(t_node **lsta, t_node **lstb, int flg);
void	ft_reverse_rotate_a(t_node **lst, int flg);
void	ft_reverse_rotate_b(t_node **lst, int flg);
void	ft_rrr(t_node **lsta, t_node **lstb, int flg);
/*UTILS*/
void	ft_lstadd(t_node **lst, t_node *new);
long	ft_atol(const char *nptr);
int		ft_size(t_node *lst);
int		ft_isdigit(int c);
int		ft_check_dup(t_node *a);

/*STACKS*/
void	ft_a_para_b(t_node **lsta, t_node **lstb);
void	ft_b_para_a(t_node **lsta, t_node **lstb);
void	ft_r_a_b(t_node **lsta, t_node **lstb, t_node *node);
void	ft_currindex(t_node *lst);
void	ft_initb(t_node *lsta, t_node *lstb);
void	ft_verify_create(t_node **lst, int ac, char **av);
void	ft_inita(t_node *lsta, t_node *lstb);
void	ft_check_target_b(t_node *lsta, t_node *ltsb);
void	ft_pushcost(t_node *lsta, t_node *lstb);
void	ft_check_target_a(t_node *lsta, t_node *ltsb);
void	ft_push(t_node **lst, t_node *node, char stack);
void	last_thing(t_node **lst);
void	ft_rev_rotate_a_b(t_node **lsta, t_node **lstb, t_node *node);
t_node	*ft_get_cheapest(t_node *lst);
void	ft_cheapest_nbr(t_node *lst);
int		ft_getindex(t_node **lst, t_node *node);
t_node	*find_min(t_node *lst);
t_node	*find_max_node(t_node *lst);
t_node	*ft_newnode(int content);
/*ALGORITHM*/
void	ft_sort(t_node **lst, t_node **lstb);
void	ft_sort_3(t_node **lst);
void	ft_sort_final(t_node **lsta, t_node **lstb);
int		ft_is_sorted(t_node *lst);
/*ERROR AND FREE*/
void	ft_error(t_node **lst);
void	ft_free_stack(t_node **stack);
/*SPLIT*/
char	**ft_split(char const *s, char c);
int		ft_free(char **new_arr, int count);
#endif
