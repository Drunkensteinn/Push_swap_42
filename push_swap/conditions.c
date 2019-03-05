/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:05:24 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 20:23:58 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

inline t_bool	condition_for_push(t_stack *stack, int32_t value)
{
	t_stack *iterator;

	iterator = stack;
	iterator = iterator->next;
	while (iterator)
	{
		if (iterator->value < value)
			return (false);
		if (iterator->head == true)
			break ;
		iterator = iterator->next;
	}
	return (true);
}

int32_t pushing_by_mediana(t_stack **a, t_stack **b, int32_t mediana,
						   t_command **list)
{
	int32_t elem;

	elem = 0;
	while (!(condition_for_push(*a, mediana)))
	{
		if ((*a)->value <= mediana)
		{
			(*a)->mediana = UNMARKED;
			op_pb(a, b, list);
			elem++;
		}
		else
			op_ra(a, b, list);
	}
	return (elem);
}

inline t_bool	condition_for_sort(t_stack *stack)
{
	if (stack->value > stack->next->value)
		return (false);
	else if (stack->next->value > stack->next->next->value &&
	((stack->next->head != true) && (stack->next->next->head != true)))
		return (false);
	return (true);
}