/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:04:47 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/24 12:41:56 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		get_arg_help(t_checker *c, int ac, char **av)
{
	char	**list;
	int		i;
	int		j;
	int		tmp;

	c->a = (int *)ft_memalloc(sizeof(int) * (c->len));
	c->b = (int *)ft_memalloc(sizeof(int) * (c->len));
	i = 0;
	tmp = -1;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			if (ft_strlen(list[j]) > 10)
			{
				ft_putstr("Error\n");
				exit(0);
			}
			c->a[++tmp] = ft_atoi(list[j]);
		}
		ft_memdel2((void ***)&list);
	}
}

int				get_arg(t_checker *c, int ac, char **av)
{
	int		i;
	int		j;
	char	**list;

	i = 0;
	c->len = 0;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			if (!ft_strisdigit(list[j]))
				return (_ERROR_);
			c->len++;
		}
		ft_memdel2((void ***)&list);
	}
	get_arg_help(c, ac, av);
	c->tmpa = c->len;
	c->tmpb = 0;
	return (_SUCCESS_);
}
