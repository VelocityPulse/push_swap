/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:29:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/22 14:05:15 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct	s_checker
{
	int			*a;
	int			*b;
	int			tmpa;
	int			tmpb;
	int			len;
	t_lstline	*begin;
}				t_checker;

int				get_arg(t_checker *c, int ac, char **av);

int				make_rules(t_checker *c);

void			push_up_sort(int *t, int len);
void			push_back_sort(int *t, int len);

void			rule_sa(t_checker *c);
void			rule_sb(t_checker *c);
void			rule_pa(t_checker *c);
void			rule_pb(t_checker *c);
void			rule_ra(t_checker *c);
void			rule_rb(t_checker *c);
void			rule_rra(t_checker *c);
void			rule_rrb(t_checker *c);

#endif
