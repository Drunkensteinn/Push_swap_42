/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:49:45 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/11 20:47:24 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int32_t *init_array(int32_t len, t_stack *stack)
{
	int32_t		*array;
	t_stack		*iterator;
	size_t		i;

	i = 0;
	iterator = stack;
	array = (int32_t *)ft_memalloc(sizeof(int32_t) * len);
	while (i < (size_t)len)
	{
		array[i] = iterator->value;
		iterator = iterator->next;
		i++;
	}
	return (array);
}

static size_t	calculate_len(size_t len)
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

int32_t *init_map(size_t len, size_t *len_map)
{
	int32_t	*map;
	size_t	i;

	i = calculate_len(len);
	*len_map = i;
	if (!(map = (int32_t *)ft_memalloc(sizeof(int32_t) * i + 1)))
		return (NULL);
	return (map);
}