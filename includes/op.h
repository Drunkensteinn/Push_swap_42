/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:20:12 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/09 16:48:40 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "push_swap.h"

/*
** Swap
*/

void		op_sa(t_stack **a, t_stack **b, t_command **list);

void		op_sb(t_stack **a, t_stack **b, t_command **list);

void		op_ss(t_stack **a, t_stack **b, t_command **list);

/*
** Push
*/

void		op_pa(t_stack **a, t_stack **b, t_command **list);

void		op_pb(t_stack **a, t_stack **b, t_command **list);

/*
** Rotate
*/

void		op_ra(t_stack **a, t_stack **b, t_command **list);

void		op_rb(t_stack **a, t_stack **b, t_command **list);

void		op_rr(t_stack **a, t_stack **b, t_command **lise);

/*
** Reverse rotatate
*/

void		op_rra(t_stack **a, t_stack **b, t_command **list);

void		op_rrb(t_stack **a, t_stack **b, t_command **list);

void		op_rrr(t_stack **a, t_stack **b, t_command **list);

/*
** Utils
*/

void		add_operation(t_command **list, char *name);

void		push(t_stack **stack, t_stack *elem, t_bool is_head);

t_stack		*pop(t_stack **stack);

#endif
