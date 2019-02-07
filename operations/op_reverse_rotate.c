/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:27:13 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/30 16:20:23 by ablizniu         ###   ########.fr       */
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

void	op_rra(t_stack **a, t_stack **b)
{
	(void)b;
	reverse_rotate(a);
}

void	op_rrb(t_stack **a, t_stack **b)
{
	(void)a;
	reverse_rotate(b);
}

void	op_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}