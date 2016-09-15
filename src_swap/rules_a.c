/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:55:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/15 15:18:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rule_sa(t_pushswap *ps)
{
	if (ps->tmpa < 2)
		return ;
	ft_swap(&ps->a[0], &ps->a[1]);
	if (PRINT_RULE)
		ft_putendl("sa");
	ps->count++;
}

void	rule_sb(t_pushswap *ps)
{
	if (ps->tmpb < 2)
		return ;
	ft_swap(&ps->b[0], &ps->b[1]);
	if (PRINT_RULE)
		ft_putendl("sb");
	ps->count++;
}

void	rule_pa(t_pushswap *ps)
{
	int		tmp;

	if (ps->tmpb < 1)
		return ;
	tmp = ps->b[0];
	push_up_sort(ps->b, ps->tmpb--);
	if (ps->tmpa > 0)
		push_back_sort(ps->a, ++ps->tmpa);
	else
		ps->tmpa++;
	ps->a[0] = tmp;
	if (PRINT_RULE)
		ft_putendl("pa");
	ps->count++;
}

void	rule_pb(t_pushswap *ps)
{
	int		tmp;

	if (ps->tmpa < 1)
		return ;
	tmp = ps->a[0];
	push_up_sort(ps->a, ps->tmpa--);
	if (ps->tmpb > 0)
		push_back_sort(ps->b, ++ps->tmpb);
	else
		ps->tmpb++;
	ps->b[0] = tmp;
	if (PRINT_RULE)
		ft_putendl("pb");
	ps->count++;
}
