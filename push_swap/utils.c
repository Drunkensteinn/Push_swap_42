/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:01:28 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 15:02:09 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mark(t_stack *stack)
{
	t_stack *iterator;
	size_t	i;

	i = 0;
	iterator = stack;
	while (i < MIN_ELEMS)
	{
		iterator->mediana = MARKED;
		iterator = iterator->next;
		i++;
	}
}

size_t	block_len(t_stack *stack)
{
	size_t	size;
	int64_t mediana;

	size = 0;
	mediana = stack->mediana;
	if (mediana == UNMARKED)
		return (0);
	while (stack->mediana == mediana)
	{
		size++;
		stack = stack->next;
		if (stack->head)
			return (size);
	}
	return (size);
}

size_t	calculate_len(size_t len)
{
	size_t i;

	i = 0;
	while (len > 1)
	{
		len = (len / 2) + (len % 2);
		i++;
	}
	return (i);
}

inline size_t	stack_length(t_stack *stack)
{
	t_stack	*iterator;
	size_t	len;

	len = 0;
	iterator = stack;
	iterator = iterator->next;
	while (iterator->head != true)
	{
		iterator = iterator->next;
		len++;
	}
	return (len + 1);
}