/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/17 17:14:06 by cchameyr         ###   ########.fr       */
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

static void		segment_sort(t_pushswao *ps, int stage)
{
	
}

void			push_swap(t_pushswap *ps)
{

	if (ps->print_display == true || ps->final_display == true)
		display(ps);
	if (algo_reverse(ps) == _SUCCESS_)
		return ;

	sample_sort_list();
	segment_sort();
}
