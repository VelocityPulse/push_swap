/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:12 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/09 12:41:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"


int			main(int argc, char **argv)
{
	t_pswap		ps;

	int i = -1;
	if (!get_arg(&ps, argc, argv))
		ft_printf("Error\n");
//	ft_printf("ac : %d\n", argc);
	while (++i < ps.alen)
		ft_printf("%d\n", ps.a[i]);
}
