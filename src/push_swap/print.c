/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:10:29 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 22:01:49 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_op(const char *op)
{
	ft_putendl(op);
}

void	print_error(const char *error)
{
	ft_putendl(error);
	exit(0);
}

void	print_status(t_stack *a)
{
	if (sort_status_check(a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}
