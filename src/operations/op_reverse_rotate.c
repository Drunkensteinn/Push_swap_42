/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:27:13 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 22:33:57 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void		reverse_rotate(t_stack **stack)
{
	if (*stack)
	{
		(*stack)->head = false;
		(*stack) = (*stack)->prev;
		(*stack)->head = true;
	}
}

void		op_rra(t_stack **a, t_stack **b, t_command **list)
{
	(void)b;
	if (a && *a)
	{
		reverse_rotate(a);
		add_operation(list, RRA);
	}
}

void		op_rrb(t_stack **a, t_stack **b, t_command **list)
{
	(void)a;
	if (b && *b)
	{
		reverse_rotate(b);
		add_operation(list, RRB);
	}
}

void		op_rrr(t_stack **a, t_stack **b, t_command **list)
{
	if ((a && *a) && (b && *b))
	{
		reverse_rotate(a);
		reverse_rotate(b);
		add_operation(list, RRR);
	}
}
