/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:05:24 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/25 22:09:27 by ablizniu         ###   ########.fr       */
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

void		pushing_by_mediana(t_stack **a, t_stack **b, int32_t mediana,
							   int32_t *elem)
{
	while (!(condition_for_push(*a, mediana)))
	{
		if ((*a)->value <= mediana)
		{
			op_pb(a, b);
			(*elem)++;
		}
		else
			op_ra(a, b);
	}
}

inline t_bool	condition_for_sort(t_stack *stack)
{
//	t_stack *iterator;
//
//	iterator = stack;
//	while (iterator->next->head != true)
//	{
//		if (iterator->value > iterator->next->value)
//			return (false);
//		iterator = iterator->next;
//	}
	if (stack->value > stack->next->value)
		return (false);
	else if (stack->next->value > stack->next->next->value)
		return (false);
	return (true);
}