/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:13:06 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 23:08:31 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/op.h"

static inline void		*get_func(char *name)
{
	if (ft_strequ(name, SA))
		return (&op_sa);
	else if (ft_strequ(name, SB))
		return (&op_sb);
	else if (ft_strequ(name, SS))
		return (&op_ss);
	else if (ft_strequ(name, PA))
		return (&op_pa);
	else if (ft_strequ(name, PB))
		return (&op_pb);
	else if (ft_strequ(name, RA))
		return (&op_ra);
	else if (ft_strequ(name, RB))
		return (&op_rb);
	else if (ft_strequ(name, RR))
		return (&op_rr);
	else if (ft_strequ(name, RRA))
		return (&op_rra);
	else if (ft_strequ(name, RRB))
		return (&op_rrb);
	else if (ft_strequ(name, RRR))
		return (&op_rrr);
	else
		print_error(INSTRUCTION_ERROR);
	return (NULL);
}

void					execute_operations(t_stack **stack_a)
{
	char				*op;
	t_stack				*stack_b;

	stack_b = NULL;
	while (get_next_line(0, &op))
	{
		if (op && *op)
			((void (*)(t_stack **, t_stack **, t_command *))get_func(op))
			(stack_a, &stack_b, NULL);
		ft_strdel(&op);
	}
}
