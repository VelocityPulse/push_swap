/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:29:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/13 11:58:59 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line.h"

#include "debug.h"

typedef struct	s_checker
{
	int			*a;
	int			*b;
	int			tmpa;
	int			tmpb;
	int			alen;
	int			blen;
	t_lstline	*begin;
}				t_checker;

int		make_rules(t_checker *c);

void	rule_sa(t_checker *c);
void	rule_sb(t_checker *c);
void	rule_ss(t_checker *c);
void	rule_pa(t_checker *c);
void	rule_pb(t_checker *c);

#endif
