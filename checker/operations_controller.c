/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:13:06 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 20:40:50 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

static inline  void		*get_func(char *name)
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
		print_error();
	return (NULL);
}

void execute_operations(t_stack **stack_a, t_stack **stack_b)
{
	char *op;

	int fd = open("../test.txt", O_RDONLY);
	while(get_next_line(fd, &op))
	{
		if (op && *op)
			((void (*)(t_stack **, t_stack **, t_command *))get_func(op))(stack_a, stack_b, NULL);
		ft_strdel(&op);
	}
}