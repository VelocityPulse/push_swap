/* ************************************************************************** */
/*                                                                            */
	/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/19 15:29:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_sort(int *t, int len)
{
	int		i;

	i = 0;
	while (++i < len)
	{
		if (t[i - 1] > t[i])
			return (i);
	}
	return (0);
}

static void		push_b(t_pushswap *ps, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		rule_pb(ps);
	}
}

static void		push_a(t_pushswap *ps, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		rotate_swap(ps);
		if (ps->b[0] < ps->b[1])
			rule_sb(ps);
		rule_pa(ps);
	}
}

static int		get_max(int *p, int len)
{
	int		max;

	max = 0;
	while (--len)
	{
		if (max < p[len])
			max = p[len];
	}
	return (max);
}

static int		swap_begin(t_pushswap *ps, int fault)
{
	push_b(ps, fault - 1);
	if (ps->a[0] > ps->b[0] && ps->a[1] < get_max(ps->b, ps->tmpb))
	{
		rule_pb(ps);
		fault++;
		while (ps->a[0] < get_max(ps->b, ps->tmpb) &&
			ps->a[0] < ps->a[ps->tmpa - 1])
			rule_ra(ps);
	}
	else
	{
		rule_sa(ps);
		if (ps->a[1] > ps->a[2])
			swap_begin(ps, 2);
	}
	push_a(ps, fault - 1);
	return (_SUCCESS_);
}

void			push_swap(t_pushswap *ps, int *a, int *b)
{
	int		fault;
	int		tmp;

	while ((fault = check_sort(a, ps->tmpa)) != 0)
	{
		if (rotate_hard_a(ps))
			;
		else
		{
			if (fault <= ps->tmpa / 2)
			{
				swap_begin(ps, fault);
				while (ps->tmpb)
					rule_pa(ps);
			}
		}
		rotate_basic_a(ps);
	}
	ft_printf("termine\n");
}
