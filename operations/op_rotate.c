/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:44 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 22:12:39 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void	rotate(t_stack **stack)
{
	if (*stack)
	{
		(*stack)->head = false;
		(*stack) = (*stack)->next;
		(*stack)->head = true;
	}
}

void op_ra(t_stack **a, t_stack **b, t_command **list)
{
	if (a && *a)
	{
		(void)b;
		rotate(a);
		add_operation(list, RA);
	}
}

void op_rb(t_stack **a, t_stack **b, t_command **list)
{
	if (b && *b)
	{
		(void)a;
		rotate(b);
		add_operation(list, RB);
	}
}

void	op_rr(t_stack **a, t_stack **b, t_command **list)
{
	if ((a && *a) && (b && *b))
	{
		rotate(a);
		rotate(b);
		print_op(RR);
	}
}

