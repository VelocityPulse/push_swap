/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:55:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/14 15:14:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "../libft/libft.h"

# include "debug.h"

typedef struct	s_pushswap
{
	int		*a;
	int		*b;
	int		tmpa;
	int		tmpb;
	int		len;
}				t_pushswap;

void	push_up_sort(int *t, int len);
void	push_back_sort(int *t, int len);

void	rule_sa(t_pushswap *ps);
void	rule_sb(t_pushswap *ps);
void	rule_pa(t_pushswap *ps);
void	rule_pb(t_pushswap *ps);
void	rule_ra(t_pushswap *ps);
void	rule_rb(t_pushswap *ps);
void	rule_rra(t_pushswap *ps);
void	rule_rrb(t_pushswap *ps);
void	rule_ss(t_pushswap *ps);
void	rule_rr(t_pushswap *ps);
void	rule_rrr(t_pushswap *ps);

#endif
