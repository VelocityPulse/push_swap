/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:58:48 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/16 14:12:31 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_sort_a(t_pushswap *ps)
{
	int		i;
	int		end;

	if (ps->tmpa < 2)
		return ;
	i = -1;
	end = ps->a[ps->tmpa - 1];
	if (ps->a[0] > end && end > ps->a[1])
		rule_ra(ps);
	else if (ps->a[0] > end)
		rule_rra(ps);
}

void	rotate_sort_b(t_pushswap *ps)
{
	if (ps->tmpb < 2)
		return ;
	while (ps->b[0] > ps->b[ps->tmpb - 1])
		rule_rrb(ps);
	while (ps->b[0] < ps->b[ps->tmpb - 1])
		rule_rb(ps);
}
