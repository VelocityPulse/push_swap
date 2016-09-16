/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:55:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/16 13:43:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "../libft/libft.h"

# define COUNT_RULE			1
# define PRINT_RULE			1
# define DISPLAY_EVERY_PILES	1
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

void			push_swap(t_pushswap *ps, int *a, int *b);
void			rotate_sort_a(t_pushswap *ps);
void			rotate_sort_b(t_pushswap *ps);


void			push_up_sort(int *t, int len);
void			push_back_sort(int *t, int len);

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
