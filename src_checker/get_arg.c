/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 12:05:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/09 12:39:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		get_arg(t_pswap *ps, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		ft_printf("|%d|\n", ft_strisdigit(av[i]));
		if (!ft_strisdigit(av[i]))
			return (_ERROR_);
	}
	ps->alen = ac - 1;
	ps->a = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	ps->blen = ac - 1;
	ps->b = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
	{
		ps->a[i] = ft_atoi(av[i]);
	}
	return (_SUCCESS_);
}
