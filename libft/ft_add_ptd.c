/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ptd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 12:09:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/04/03 12:10:38 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ptd		ft_add_ptd(t_ptd pt1, t_ptd pt2)
{
	t_ptd		pt3;

	pt3.x = pt1.x + pt2.x;
	pt3.y = pt1.y + pt2.y;
	return (pt3);
}
