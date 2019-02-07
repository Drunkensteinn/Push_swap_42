/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:20:12 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/30 16:21:27 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
#define OP_H

#include "../push_swap.h"


void		op_sa(t_stack **a, t_stack **b);

void		op_sb(t_stack **a, t_stack **b);

void		op_ss(t_stack **a, t_stack **b);


void		op_pa(t_stack **a, t_stack **b);

void		op_pb(t_stack **a, t_stack **b);


void		op_ra(t_stack **a, t_stack **b);

void		op_rb(t_stack **a, t_stack **b);

void		op_rr(t_stack **a, t_stack **b);


void		op_rra(t_stack **a, t_stack **b);

void		op_rrb(t_stack **a, t_stack **b);

void		op_rrr(t_stack **a, t_stack **b);


void		push(t_stack **stack, t_stack *elem, t_bool is_head);

t_stack		*pop(t_stack **stack);

size_t		stack_length(t_stack *stack);


#endif
