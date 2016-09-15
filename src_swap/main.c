/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/15 11:07:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_arg(t_pushswap *ps, int ac, char **av)
{
	int		i;

	i = -1;
	while (++i < ac)
	{
		if (!ft_strisdigit(av[i]))
			return (_ERROR_);
	}
	ps->len = ac - 1;
	ps->tmpa = ps->len;
	ps->tmpb = 0;
	ps->a = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	ps->b = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
		ps->a[i - 1] = ft_atoi(av[i]);
	return (_SUCCESS_);
}

static int		check_duplicate(t_pushswap *ps)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= ps->len)
	{
		j = -1;
		while (++j <= ps->len)
		{
			if (j != i)
			{
				if (ps->a[i] == ps->a[j])
					return (_ERROR_);
			}
		}
	}
	return (_SUCCESS_);
}

static int		check_basic_sort(t_pushswap *ps)
{
	int		i;

	i = ps->len - 1;
	while (--i >= 0)
	{
		if (ps->a[i] > ps->a[i + 1])
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

int				main(int argc, char **argv)
{
	t_pushswap		ps;

	if (!get_arg(&ps, argc, argv))
		ft_printf("Error\n");
	if (!check_duplicate(&ps))
		ft_printf("Error\n");
	if (!check_basic_sort(&ps))
		push_swap(&ps, ps.a, ps.b);

	return (0);
}

/*
** test :
**	ft_printf("pile A\n");
**	int i = -1;
**	while (++i < ps.tmpa)
**		ft_printf("->%d\n", ps.a[i]);
**	i = -1;
**	ft_printf("pile B\n");
**	while (++i < ps.tmpb)
**		ft_printf("->%d\n", ps.b[i]);
*/
