/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:12 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/21 11:19:42 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		get_rules(t_checker *c)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
		c->begin = ft_add_lstline(c->begin, line);
	if (c->begin == NULL)
		return (_ERROR_);
	return (_SUCCESS_);
}

static int		get_arg(t_checker *c, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strisdigit(av[i]))
			return (_ERROR_);
	}
	c->len = ac - 1;
	c->a = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	c->b = (int *)ft_memalloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
		c->a[i - 1] = ft_atoi(av[i]);
	return (_SUCCESS_);
}

static int		check_dublicate(t_checker *c)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= c->len)
	{
		j = -1;
		while (++j <= c->len)
		{
			if (j != i)
			{
				if (c->a[i] == c->a[j])
					return (_ERROR_);
			}
		}
	}
	return (_SUCCESS_);
}

static int		check_sort(t_checker *c)
{
	int		i;

	if (c->tmpb != 0)
		return (_ERROR_);
	i = c->len - 1;
	while (--i >= 0)
	{
		if (c->a[i] > c->a[i + 1])
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

int				main(int argc, char **argv)
{
	t_checker	c;

	if (!get_arg(&c, argc, argv))
		ft_putstr_fd("Error\n", 2);
	else if (!check_dublicate(&c))
		ft_putstr_fd("Error\n", 2);
	else if (!get_rules(&c))
		ft_putstr_fd("Error\n", 2);
	else if (!make_rules(&c))
		ft_putstr_fd("Error\n", 2);
	else if (!check_sort(&c))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	c.begin = ft_lstline_del(c.begin);
	ft_memdel((void **)&c.a);
	ft_memdel((void **)&c.b);
	return (0);
}

/*
** test :
**	else
**	{
**		ft_printf("pile A\n");
**		while (++i < c.tmpa)
**			ft_printf("->%d\n", c.a[i]);
**		i = -1;
**		ft_printf("pile B\n");
**		while (++i < c.tmpb)
**			ft_printf("->%d\n", c.b[i]);
**	}
*/
