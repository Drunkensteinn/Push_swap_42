/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:49:45 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/01 19:05:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int32_t *init_array(int32_t len, char **data)
{
	int32_t		*array;
	size_t		i;

	i = 0;
	array = (int32_t *)ft_memalloc(sizeof(int32_t) * len);
	while (i < (size_t)len)
	{
		array[i] = ft_atoi(data[i]);
		i++;
	}
	return (array);
}