/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:35:03 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 16:36:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		**validate_single_array(char *array, int32_t *len)
{
	char	**validated_array;
	int32_t	i;

	i = 0;
	if (ft_strlen(array) > *len)
	{
		validated_array = ft_strsplit(array, ' ');
		while (validated_array[i])
			i++;
		*len = i;
		return (validated_array);
	}
	return (NULL);
}

t_bool		validate_duplication(t_stack *stack)
{
	int32_t *arr;
	size_t len;
	size_t i;
	size_t j;

	i = 0;
	len = stack_length(stack);
	arr = init_array(stack, len);
	while (i < len)
	{
		j = 0;
		while (j + i < len)
		{
			if (j && (arr[i] == arr[i + j]))
			{
				ft_memdel((void *)&arr);
				return (true);
			}
			j++;
		}
		i++;
	}
	ft_memdel((void *)&arr);
	return (false);
}

t_bool		array_validation(int32_t len, char **array)
{
	size_t i;

	i = 0;
	while (i < (size_t)len)
	{
		if (!ft_isint(array[i], false))
		{
			print_error(INVALID_DATAS_ERROR);
			return (false);
		}
		i++;
	}
	return (true);
}
