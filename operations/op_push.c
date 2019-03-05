/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:58:39 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 20:56:18 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void		op_push(t_stack **to, t_stack **from)
{
	if (*from)
		push(to, pop(from), true);
}

void		op_pa(t_stack **a, t_stack **b, t_command **list)
{
	if (a && *a)
	{
		op_push(a, b);
		add_operation(list, PA);
	}
}

void		op_pb(t_stack **a, t_stack **b, t_command **list)
{
	if (a && *a)
	{
		op_push(b, a);
		add_operation(list, PB);
	}
}
