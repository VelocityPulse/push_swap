/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:16:48 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/14 15:13:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_up_sort(int *t, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		t[i] = t[i + 1];
	t[len - 1] = 0;
}

void	push_back_sort(int *t, int len)
{
	int		i;

	i = len;
	while (--i >= 0)
		t[i] = t[i - 1];
	t[i] = 0;
}

/*
** push_up_sort 1 2 3 -> 2 3 0   (--)
** push_back_sort 1 2 3 -> 0 1 2  (++)
*/
