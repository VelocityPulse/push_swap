/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:55:20 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/14 11:01:47 by cchameyr         ###   ########.fr       */
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

void	rule_sa(t_pushswap *c);
void	rule_sb(t_pushswap *c);
void	rule_pa(t_pushswap *c);
void	rule_pb(t_pushswap *c);
void	rule_ra(t_pushswap *c);
void	rule_rb(t_pushswap *c);
void	rule_rra(t_pushswap *c);
void	rule_rrb(t_pushswap *c);

#endif
