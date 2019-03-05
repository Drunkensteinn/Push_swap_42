/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:19:42 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 20:57:04 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

static void op_swap(t_stack **stack)
{
	t_stack *next;
	t_stack *head;

	head = (*stack);
	if ((*stack) && (*stack)->next)
	{
		next = pop(stack);
		push(&(*stack)->next, next, false);
		(*stack)->head = true;
	}
}

void op_sa(t_stack **a, t_stack **b, t_command **list)
{
	(void)b;
	op_swap(a);
	add_operation(list, SA);
}

void op_sb(t_stack **a, t_stack **b, t_command **list)
{
	(void)a;
	op_swap(b);
	add_operation(list, SB);
}

void	op_ss(t_stack **a, t_stack **b, t_command **list)
{
	op_swap(a);
	op_swap(b);
	print_op(SS);
}
