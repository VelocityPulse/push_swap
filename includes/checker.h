/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:29:22 by cchameyr          #+#    #+#             */
/*   Updated: 2016/09/09 12:35:19 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

#include "debug.h"

typedef struct	s_pswap
{
	int		*a;
	int		alen;
	int		*b;
	int		blen;
}				t_pswap;

int		get_arg(t_pswap *ps, int ac, char **av);

#endif
