/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:27:13 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 22:14:31 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	reverse_rotate(t_stack **stack)
{
	if (*stack)
	{
		(*stack)->head = false;
		(*stack) = (*stack)->prev;
		(*stack)->head = true;
	}
}

void op_rra(t_stack **a, t_stack **b, t_command **list)
{
	(void)b;
	reverse_rotate(a);
	add_operation(list, RRA);
}

void op_rrb(t_stack **a, t_stack **b, t_command **list)
{
	(void)a;
	reverse_rotate(b);
	add_operation(list, RRB);
}

void	op_rrr(t_stack **a, t_stack **b, t_command **list)
{
	reverse_rotate(a);
	reverse_rotate(b);
	print_op(RRR);
}