/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:58:48 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/15 13:04:38 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_sort_a(t_pushswap *ps)
{
	if (ps->tmpa < 2)
		return ;
	while (ps->a[0] > ps->a[ps->tmpa - 1])
		rule_rra(ps);
//	while (ps->a[0] < ps->a[ps->tmpa - 1])
//		rule_ra(ps);
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
