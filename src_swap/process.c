/* ************************************************************************** */
/*                                                                            */
	/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/21 10:32:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_max(int *p, int len)
{
	int		max;

	max = -2147483648;
	while (len--)
	{
		if (max < p[len])
			max = p[len];
	}
	return (max);
}

static int		get_min(int *p, int len)
{
	int		min;

	min = 2147483647;
	while (--len)
	{
		if (min > p[len])
			min = p[len];
	}
	return (min);
}

static int		get_index_up(t_pushswap *ps, int present)
{
	int		i;
	int		tmp;

	i = -1;
	tmp =  2147483647;
	while (++i < ps->tmpa)
	{
		if (ps->a[i] > present && ps->a[i] < tmp)
			tmp = ps->a[i];
	}
	i = -1;
	while (++i <= ps->tmpa)
	{
		if (ps->a[i] == tmp)
			return (i);
	}
	return (_ERROR_);
}

static int		get_index(t_pushswap *ps, int present)
{
	int		i;

	i = -1;
	while (++i < ps->tmpa)
	{
		if (ps->a[i] == present)
			break;
	}
	return (i);
}

void			push_swap(t_pushswap *ps)
{
	int		i;
	int		min;

	min = get_min(ps->a, ps->tmpa);
	while (min < get_max(ps->a, ps->tmpa))
	{
		i = get_index(ps, min);
		if (i < ps->tmpa / 2)
		{
			while (i--)
				rule_ra(ps);
		}
		else
		{
			while (++i <= ps->tmpa)
				rule_rra(ps);
		}
		rule_pb(ps);
		min = ps->a[get_index_up(ps, min)];
	}
	while (ps->tmpb)
		rule_pa(ps);
}
