/* ************************************************************************** */
/*                                                                            */
	/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/19 17:47:36 by                  ###   ########.fr       */
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
		while (rotate_swap(ps))
			;
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
	ft_printf("--------BEGIN---------\n");
	push_b(ps, fault - 1);
	if (ps->tmpb && ps->a[0] > ps->b[0] && ps->a[1] < get_max(ps->b, ps->tmpb))
	{
		rule_pb(ps);
		fault += 2;
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
	push_a(ps, fault);
	return (_SUCCESS_);
}

static int		swap_after(t_pushswap *ps, int fault)
{
	int		tmp;
	
	ft_printf("----------AFTER----------\n");
	while (1);
	tmp = fault;
	while (--tmp)
		rule_pb(ps);
	rule_ra(ps);
	tmp = fault;
	while (--tmp)
	{
//		if ()
	}
	return (_SUCCESS_);
}

void			free_good(t_pushswap *ps)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 0;
	while (flag == 0 && ++i < ps->tmpa)
	{
		j = i;
		while (flag == 0 && ++j < ps->tmpa)
		{
			if (ps->a[j] < ps->a[i])
				flag = 1;
		}
	}
	while (i--)
		rule_pb(ps);
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
//				while (1);
//				while (ps->tmpb)
//					rule_pa(ps);
			}
			else
			{
				free_good(ps);
		//		swap_after(ps, fault);
			}
		}
		rotate_basic_a(ps);
	}
	while (ps->tmpb)
		rule_pa(ps);
	ft_printf("termine\n");
}
