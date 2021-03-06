/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:16:48 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/21 17:20:17 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push_up_sort(int *t, int len)
{
	int		i;

	i = -1;
	while (++i < len - 1)
		t[i] = t[i + 1];
	t[len - 1] = 0;
}

void	push_back_sort(int *t, int len)
{
	while (--len > 0)
		t[len] = t[len - 1];
	t[len] = 0;
}

/*
** push_up_sort 1 2 3 -> 2 3 0   (--)
** push_back_sort 1 2 3 -> 0 1 2  (++)
*/
