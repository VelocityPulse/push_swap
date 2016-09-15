/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/15 17:06:27 by cchameyr         ###   ########.fr       */
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

static void		push_good_b(t_pushswap *ps, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		rule_pb(ps);
}

static void		push_good_a(t_pushswap *ps, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		rule_pa(ps);
}

void			push_swap(t_pushswap *ps, int *a, int *b)
{
	int		fault;
	int		tmp;

	rotate_sort_a(ps);
	while ((fault = check_sort(a, ps->tmpa)) != 0)
	{
		if (fault == 1)
			rule_sa(ps);
		if (fault - 1 > ps->tmpa / 2)
		{
			tmp = fault;
			while (++tmp < ps->tmpa)
				rule_rra(ps);
			tmp = (ps->tmpa - fault) - 1;
			push_good_b(ps, tmp);
			rule_rra(ps);
			push_good_a(ps, tmp);
			while (tmp--)
				rule_ra(ps);
		}
		else
		{
			push_good_b(ps, fault - 1);
			push_swap(ps, ps->a, ps->b);
			push_good_a(ps, fault - 1);
		}
	}
}
