/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:44 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/10 17:03:44 by ablizniu         ###   ########.fr       */
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

void	op_ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	print_op(RA);
}

void	op_rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	print_op(RB);
}

void	op_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	print_op(RR);
}

