/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:41:44 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/30 13:21:27 by ablizniu         ###   ########.fr       */
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
}

void	op_rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
}

void	op_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

