/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:49:54 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/18 18:09:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		segment_len(int len)
{
	if (len >= 4000)
		return (35);
	if (len >= 2000)
		return (25);
	if (len >= 1000)
		return (20);
	if (len >= 500)
		return (14);
	if (len >= 400)
		return (12);
	if (len >= 300)
		return (10);
	if (len >= 200)
		return (8);
	if (len >= 100)
		return (5);
	if (len >= 25)
		return (4);
	return (2);
}
