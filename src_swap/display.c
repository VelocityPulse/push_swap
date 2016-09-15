/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:21:30 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/15 15:41:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display(t_pushswap *ps)
{
	int		i;

	i = -1;
	ft_putendl("Pile A");
	while (++i < ps->tmpa)
		ft_printf("->%d", ps->a[i]);
	i = -1;
	ft_putendl("\nPile B");
	while (++i < ps->tmpb)
		ft_printf("->%d", ps->b[i]);
	if (ps->tmpb > 0)
		ft_putchar('\n');
	ft_putchar('\n');
}
