/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:55:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/21 11:07:30 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "../libft/libft.h"

# define COUNT_RULE			0
# define PRINT_RULE			1
# define DISPLAY_EVERY_PILES	0
# define DISPLAY_FINAL_PILES	0

# include "debug.h"

typedef struct	s_pushswap
{
	int		*a;
	int		*b;
	int		tmpa;
	int		tmpb;
	int		len;
	int		count;
}				t_pushswap;

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
