/* ************************************************************************** */
/*                                                                            */
	/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/16 16:42:26 by cchameyr         ###   ########.fr       */
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
		if (ps->b[0] < ps->b[1])
		{
			if (ps->tmpb > 1 && ps->b[0] > ps->b[2])
				rule_sb(ps);
		}
	}
	ft_printf("end\n");
}

static void		push_a(t_pushswap *ps, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		rule_pa(ps);
		if (ps->a[0] > ps->a[1])
				rule_sa(ps);
	}
}

static int		swap_begin(t_pushswap *ps, int fault)
{
	YOLO
	push_b(ps, fault - 1);
	rule_sa(ps);
	if (ps->a[1] > ps->a[2])
		swap_begin(ps, 2);
	push_a(ps, fault - 1);
	return (_SUCCESS_);
}


void			push_swap(t_pushswap *ps, int *a, int *b)
{
	int		fault;
	int		tmp;

	while ((fault = check_sort(a, ps->tmpa)) != 0)
	{
		if (swap_begin(ps, fault))
//			while (1);
			ft_printf("end mode1\n");
		else if (rotate_basic_a(ps))
			ft_printf("end mode2\n");
		else if (rotate_hard_a(ps))
			ft_printf("end mode3\n");
	}
}
