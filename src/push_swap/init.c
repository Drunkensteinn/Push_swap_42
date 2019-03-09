/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:49:45 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 22:10:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int32_t			*init_array(t_stack *stack, size_t len)
{
	int32_t		*array;
	t_stack		*iterator;
	size_t		i;

	i = 0;
	iterator = stack;
	if (!(array = (int32_t *)ft_memalloc(sizeof(int32_t) * len + 1)))
		return (NULL);
	while (i < len)
	{
		array[i] = iterator->value;
		iterator = iterator->next;
		i++;
	}
	return (array);
}

int32_t			*init_map(size_t len, size_t *len_map)
{
	int32_t		*map;
	size_t		i;

	i = calculate_len(len);
	*len_map = i;
	if (!(map = (int32_t *)ft_memalloc(sizeof(int32_t) * i)))
		return (NULL);
	return (map);
}
