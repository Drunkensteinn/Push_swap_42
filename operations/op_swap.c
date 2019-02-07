/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:19:42 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/30 16:56:28 by ablizniu         ###   ########.fr       */
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
	}
}

void	op_sa(t_stack **a, t_stack **b)
{
	(void)b;
	op_swap(a);
}

void	op_sb(t_stack **a, t_stack **b)
{
	(void)a;
	op_swap(b);
}

void	op_ss(t_stack **a, t_stack **b)
{
	op_swap(a);
	op_swap(b);
}
