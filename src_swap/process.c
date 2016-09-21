/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/21 11:02:07 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			push_swap(t_pushswap *ps)
{
	int		i;
	int		min;

	min = get_min(ps->a, ps->tmpa);
	while (min < get_max(ps->a, ps->tmpa))
	{
		i = get_index(ps, min);
		if (get_fault(ps->a, ps->tmpa) == 0)
			break ;
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
		if (get_fault(ps->a, ps->tmpa) == 0)
			break ;
		rule_pb(ps);
		min = ps->a[get_index_up(ps, min)];
	}
	while (ps->tmpb)
		rule_pa(ps);
}
