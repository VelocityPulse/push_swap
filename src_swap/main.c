/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:04 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/21 17:04:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		get_arg_help(t_pushswap *ps, int ac, char **av)
{
	char	**list;
	int		i;
	int		j;
	int		tmp;

	ps->a = (int *)ft_memalloc(sizeof(int) * (ps->len));
	ps->b = (int *)ft_memalloc(sizeof(int) * (ps->len));
	i = 0;
	tmp = -1;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
			ps->a[++tmp] = ft_atoi(list[j]);
		ft_memdel2((void ***)&list);
	}
	ps->tmpa = ps->len;
	ps->tmpb = 0;
}

static int		get_arg(t_pushswap *ps, int ac, char **av)
{
	int		i;
	int		j;
	char	**list;

	i = 0;
	ps->len = 0;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			if (!ft_strisdigit(list[j]))
				return (_ERROR_);
			ps->len++;
		}
		ft_memdel2((void ***)&list);
	}
	get_arg_help(ps, ac, av);
	return (_SUCCESS_);
}

static int		check_duplicate(t_pushswap *ps)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ps->len)
	{
		j = -1;
		while (++j < ps->len)
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

	ps.count = 0;
	if (!get_arg(&ps, argc, argv))
		ft_putstr_fd("Error\n", 2);
	else if (!check_duplicate(&ps))
		ft_putstr_fd("Error\n", 2);
	else if (!check_basic_sort(&ps))
		push_swap(&ps);
	if (DISPLAY_FINAL_PILES)
		display(&ps);
	if (COUNT_RULE)
		ft_printf("number rules : %d\n", ps.count);
	ft_memdel((void **)&ps.a);
	ft_memdel((void **)&ps.b);
	return (0);
}
