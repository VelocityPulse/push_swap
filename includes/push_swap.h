/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:55:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/22 11:49:50 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "../libft/libft.h"

typedef struct	s_pushswap
{
	int		*a;
	int		*b;
	int		tmpa;
	int		tmpb;
	int		len;
	int		count;
	int		arg;
	t_bool	count_rules;
	t_bool	print_rules;
	t_bool	final_display;
	t_bool	print_display;
}				t_pushswap;

int				get_arg(t_pushswap *ps, int ac, char **av, int arg);

void			push_swap(t_pushswap *ps);

void			push_up_sort(int *t, int len);
void			push_back_sort(int *t, int len);

int				get_fault(int *p, int len);
int				get_max(int *p, int len);
int				get_min(int *p, int len);
int				get_index_up(t_pushswap *ps, int present);
int				get_index(t_pushswap *ps, int present);

void			rule_sa(t_pushswap *ps);
void			rule_sb(t_pushswap *ps);
void			rule_pa(t_pushswap *ps);
void			rule_pb(t_pushswap *ps);
void			rule_ra(t_pushswap *ps);
void			rule_rb(t_pushswap *ps);
void			rule_rra(t_pushswap *ps);
void			rule_rrb(t_pushswap *ps);
void			rule_ss(t_pushswap *ps);
void			rule_rr(t_pushswap *ps);
void			rule_rrr(t_pushswap *ps);

void			display(t_pushswap *ps);

#endif
