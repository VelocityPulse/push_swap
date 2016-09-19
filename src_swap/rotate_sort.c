/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:58:48 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/19 17:41:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				rotate_basic_a(t_pushswap *ps)
{
	int		i;
	int		end;

	if (ps->tmpa < 2)
		return (_ERROR_);
	i = -1;
	end = ps->a[ps->tmpa - 1];
	if (ps->a[0] > end && end > ps->a[1])
	{
		rule_ra(ps);
		return (_SUCCESS_);
	}
	else if (ps->a[0] > end)
	{
		rule_rra(ps);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static void		rotate_hard_help(t_pushswap *ps, int i, int tmp, int tmp2)
{
	int		factor_good;

	factor_good = 0;
	while (ps->a[tmp - 1] < ps->a[tmp])
	{
		factor_good++;
		tmp--;
	}
	tmp2 = ps->tmpa;
	tmp = (tmp2 - i) + factor_good;
	while (tmp--)
		rule_rra(ps);
	tmp = factor_good + 1;
	if (tmp == 1 && (tmp2 - i) - 1 <= 0)
		return ;
	while (tmp--)
		rule_pb(ps);
	tmp = (tmp2 - i) - 1;
	while (tmp--)
		rule_ra(ps);
	tmp = factor_good + 1;
	while (tmp--)
		rule_pa(ps);
}

int				rotate_hard_a(t_pushswap *ps)
{
	int		i;
	int		factor_good;

	i = ps->tmpa;
	factor_good = 0;
	while (--i >= ps->tmpa / 2)
	{
		if (ps->a[i] < ps->a[0])
		{
			rotate_hard_help(ps, i, i, ps->tmpa);
			return (_SUCCESS_);
		}
	}
	return (_ERROR_);
}

int			rotate_swap(t_pushswap *ps)
{
	int		i;
	int		i_end;
	int		tmp;

	i_end = ps->tmpa;
	i = 0;
	while (ps->a[i_end - i] < ps->a[0] && i < ps->tmpa)
	{
		if (ps->a[(i_end - i) - 1] < ps->a[0])
			i++;
		else
			break;
	}
	if (i > 0 && ps->a[i_end - i] > ps->b[0])
	{
		tmp = i;
		while (tmp--)
			rule_rra(ps);
		rule_pb(ps);
		tmp = i;
		while (--tmp)
		{
			if (ps->a[0] > ps->a[1])
				rule_sa(ps);
			rule_ra(ps);
		}
		return (_SUCCESS_);
	}
	else if (ps->tmpb && ps->a[i_end - 1] < ps->a[0] &&
			ps->a[i_end - 1] > ps->b[0])
	{
		rule_rra(ps);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}
