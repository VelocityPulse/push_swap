/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/18 10:28:20 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		algo_reverse(t_pushswap *ps)
{
	int		cpt;

	cpt = 0;
	while (cpt < ps->tmpa - 1)
	{
		if (ps->a[cpt] < ps->a[cpt + 1])
			return (_ERROR_);
		cpt++;
	}
	while (ps->tmpa > 1)
	{
		rule_rra(ps);
		rule_pb(ps);
	}
	while (ps->tmpb)
		rule_pa(ps);
	return (_SUCCESS_);
}

static void		insertion_algo(t_pushswap *ps)
{
	int		index;

	while (ps->tmpb)
	{
		index = get_index(ps->b, ps->tmpb, get_max(ps->b, ps->tmpb));
		if (index < ps->tmpb / 2)
		{
			while (index--)
				rule_rb(ps);
		}
		else
		{
			while (++index <= ps->tmpb)
				rule_rrb(ps);
		}
		rule_pa(ps);
	}
}

static void		segment_sort(t_pushswap *ps, int stage)
{
	int		cpt;
	int		len;

	cpt = -1;
	len = ps->tmpa;
	while (get_min(ps->a, ps->tmpa) < stage)
	{
		while (ps->a[0] >= stage)
			rule_ra(ps);
		rule_pb(ps);
	}
}

void			push_swap(t_pushswap *ps)
{
	int		*sorted;
	int		cpt;
	int		stage;
	int		segment;

	if (ps->print_display == true || ps->final_display == true)
		display(ps);
	if (algo_reverse(ps) == _SUCCESS_)
		return ;
	
	sorted = ft_intdup(ps->a, ps->len);
	sort_sample_list(sorted, 0, ps->len - 1);
	segment = segment_len(ps->len);
	cpt = segment;
	stage = ps->len / segment;
	while (cpt-- > 1)
	{
		segment_sort(ps, sorted[stage]);
		stage += segment;
	}
	while (ps->tmpa)
		rule_pb(ps);
	insertion_algo(ps);
	ft_memdel((void **)sorted);
}
