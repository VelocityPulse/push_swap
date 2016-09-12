/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:55:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/12 15:41:49 by cchameyr         ###   ########.fr       */
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
	c->a[++c->tmpa] = c->b[0];
	i = -1;
	while (++i <= c->tmpb)
		c->b[i] = c->b[i + 1];
	c->b[c->tmpb--] = 0;
}
