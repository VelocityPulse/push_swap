/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:34:54 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/22 13:39:24 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_fault(int *p, int len)
{
	int		i;

	i = 0;
	while (++i < len)
	{
		if (p[i - 1] > p[i])
			return (i);
	}
	return (0);
}

int		get_max(int *p, int len)
{
	int		max;

	max = -2147483648;
	while (len--)
	{
		if (max < p[len])
			max = p[len];
	}
	return (max);
}

int		get_min(int *p, int len)
{
	int		min;

	min = 2147483647;
	while (len--)
	{
		if (min > p[len])
			min = p[len];
	}
	return (min);
}

int		get_index_up(t_pushswap *ps, int present)
{
	int		i;
	int		tmp;

	i = -1;
	tmp =  2147483647;
	while (++i < ps->tmpa)
	{
		if (ps->a[i] > present && ps->a[i] < tmp)
			tmp = ps->a[i];
	}
	i = -1;
	while (++i <= ps->tmpa)
	{
		if (ps->a[i] == tmp)
			return (i);
	}
	return (_ERROR_);
}

int		get_index(t_pushswap *ps, int present)
{
	int		i;

	i = -1;
	while (++i < ps->tmpa)
	{
		if (ps->a[i] == present)
			break;
	}
	return (i);
}
