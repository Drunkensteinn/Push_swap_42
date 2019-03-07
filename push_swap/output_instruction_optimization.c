/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_instruction_optimization.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:34:15 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/06 21:30:10 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/op.h"

t_bool	permanent_replacemant_second_part(t_command **iterator)
{
	if (ft_strequ((*iterator)->command, PB) &&
		ft_strequ((*iterator)->next->command, PA))
	{
		*iterator = remove_permanently(*iterator);
		return (true);
	}
	if ((ft_strequ((*iterator)->command, RB) &&
	ft_strequ((*iterator)->next->command, RRB)) ||
	(ft_strequ((*iterator)->command, RRB) &&
	ft_strequ((*iterator)->next->command, RB)))
	{
		*iterator = remove_permanently(*iterator);
		return (true);
	}
	if ((ft_strequ((*iterator)->command, RA) &&
	ft_strequ((*iterator)->next->command, RRA)) ||
	(ft_strequ((*iterator)->command, RRA) &&
	ft_strequ((*iterator)->next->command, RA)))
	{
		*iterator = remove_permanently(*iterator);
		return (true);
	}
	return (false);
}

t_bool	permanent_replacemant_first_part(t_command **iterator)
{
	if (ft_strequ((*iterator)->command, SA) &&
	ft_strequ((*iterator)->next->command, SA))
	{
		*iterator = remove_permanently(*iterator);
		return (true);
	}
	if (ft_strequ((*iterator)->command, SB) &&
	ft_strequ((*iterator)->next->command, SB))
	{
		*iterator = remove_permanently(*iterator);
		return (true);
	}
	if (ft_strequ((*iterator)->command, PA) &&
	ft_strequ((*iterator)->next->command, PB))
	{
		*iterator = remove_permanently(*iterator);
		return (true);
	}
	return (false);
}

t_bool	permanent_replacemant_add(t_command **iterator)
{
	if ((ft_strequ((*iterator)->command, RA) &&
	ft_strequ((*iterator)->next->command, RB)) ||
	(ft_strequ((*iterator)->command, RB) &&
	ft_strequ((*iterator)->next->command, RA)))
	{
		*iterator = remove_and_add((*iterator), (*iterator)->next, RR);
		return (true);
	}
	if ((ft_strequ((*iterator)->command, SA) &&
	ft_strequ((*iterator)->next->command, SB)) ||
	(ft_strequ((*iterator)->command, SB) &&
	ft_strequ((*iterator)->next->command, SA)))
	{
		*iterator = remove_and_add((*iterator), (*iterator)->next, SS);
		return (true);
	}
	if ((ft_strequ((*iterator)->command, RRA) &&
	ft_strequ((*iterator)->next->command, RRB)) ||
	(ft_strequ((*iterator)->command, RRB) &&
	ft_strequ((*iterator)->next->command, RRA)))
	{
		*iterator = remove_and_add((*iterator), (*iterator)->next, RRR);
		return (true);
	}
	return (false);
}

void	optimize_commands(t_command *lst)
{
	t_command *iterator;

	iterator = lst;
	while (iterator && (iterator)->next)
	{
		if (permanent_replacemant_first_part(&iterator))
			continue;
		if (permanent_replacemant_second_part(&iterator))
			continue;
		if (permanent_replacemant_add(&iterator))
			continue;
		(iterator) = (iterator)->next;
	}
}