/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:55:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/13 12:13:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rule_sa(t_checker *c)
{
	if (c->alen < 2)
		return ;
	ft_swap(&c->a[0], &c->a[1]);
}

void	rule_sb(t_checker *c)
{
	if (c->tmpb < 2)
		return ;
	ft_swap(&c->b[0], &c->b[1]);
}

void	rule_ss(t_checker *c)
{
	rule_sa(c);
	rule_sb(c);
}

void	rule_pa(t_checker *c)
{
	int		i;

	if (c->tmpb < 1)
		return ;
	i = c->tmpa + 1;
	while (--i >= 0)
		c->a[i + 1] = c->a[i];
	c->a[i] = c->b[0];
	i = -1;
	while (++i <= c->tmpb)
		c->b[i] = c->b[i + 1];
	c->b[c->tmpb--] = 0;
}

void	rule_pb(t_checker *c)
{
	int		i;

	if (c->tmpa < 1)
		return ;
	i = c->tmpb + 1;
	while (--i >= 0)
		c->b[i + 1] = c->b[i];
	c->b[i] = c->a[0];
	i = -1;
	while (++i <= c->tmpa)
		c->a[i] = c->a[i + 1];
	c->a[c->tmpb--] = 0;
}
