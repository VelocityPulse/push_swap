/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:46:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/14 10:49:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		easy_rule(t_checker *c, char *rule)
{
	if (ft_strncmp(rule, "ss", 2) == 0)
	{
		rule_sa(c);
		rule_sb(c);
	}
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		rule_rra(c);
		rule_rrb(c);
	}
	else if (ft_strncmp(rule, "rr", 2) == 0)
	{
		rule_ra(c);
		rule_rb(c);
	}
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

static int		select_rule(t_checker *c, char *rule)
{
	if (ft_strncmp(rule, "sa", 2) == 0)
		rule_sa(c);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		rule_sb(c);
	else if (ft_strncmp(rule, "pa", 2) == 0)
		rule_pa(c);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		rule_pb(c);
	else if (ft_strncmp(rule, "ra", 2) == 0)
		rule_ra(c);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rule_rb(c);
	else if (ft_strncmp(rule, "rra", 3) == 0)
		rule_rra(c);
	else if (ft_strncmp(rule, "rrb", 3) == 0)
		rule_rrb(c);
	else if (easy_rule(c, rule) == 1)
		;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int				make_rules(t_checker *c)
{
	t_lstline	*list;

	list = c->begin;
	c->tmpa = c->len;
	c->tmpb = 0;
	while (list)
	{
		if (!select_rule(c, list->line))
			return (_ERROR_);
		list = list->next;
	}
	return (_SUCCESS_);
}
