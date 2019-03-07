/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:13:37 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 16:30:29 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool		sort_status_check(t_stack *stack)
{
	t_stack *iterator;

	iterator = stack;
	if (stack)
	{
		while (iterator->next->head != true)
		{
			if (!ASCENDING(iterator->value, iterator->next->value))
				return (false);
			iterator = iterator->next;
		}
	}
	else
		print_error(INVALID_DATAS_ERROR);
	return (true);
}