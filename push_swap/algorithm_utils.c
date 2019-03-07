/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:49:15 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/06 18:53:28 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *search_elem(t_stack *stack, size_t len)
{
	size_t	i;
	t_stack *iterator;

	i = 0;
	iterator = stack;
	while (len > i)
	{
		iterator = iterator->prev;
		i++;
	}
	return (iterator);
}

void			write_in_mediana(t_stack *stack, size_t len, int32_t mediana)
{
	t_stack *iterator;
	size_t i;

	i = 0;
	iterator = stack;
	while (iterator && i < len)
	{
		stack->mediana = mediana;
		stack = stack->next;
		i++;
	}
}

t_bool			is_push(t_stack *stack, int64_t mediana, const size_t *len,
				t_bool direction)
{
	size_t iter;
	t_stack *iterator;

	iter = 0;
	iterator = stack;
	while (iter < *len)
	{
		if (direction && iterator->value > mediana)
			return (true);
		if (!direction && iterator->value <= mediana)
			return (true);
		iterator = iterator->next;
		iter++;
	}
	return (false);
}