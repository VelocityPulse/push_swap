/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:15:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/15 11:35:28 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_sort(int *t, int len)
{
	int		i;

	i = 0;
	while (++i <= len)
	{
		if (t[i - 1] > t[i])
			return (i);
	}
	return (0);
}

static int		rotate_sort(t_pushswap *ps)
{
	// faire des rotates pour a et b 
}

void			push_swap(t_pushswap *ps, int *a, int *b)
{
	int		fault;

	premide_sort(s, ps->tmpa);
	while ((fault = check_sort(a, ps->tmpa)) != 0)
	{
		if (fault == 1)
			rule_sa(ps);

	}
}
