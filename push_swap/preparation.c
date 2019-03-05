/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:50:10 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/05 13:08:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int32_t search_mediana(int32_t *array, size_t len)
{
	int32_t		mediana;

	quick_sort(array, 0, (int32_t)(len - 1));
	mediana = array[dilimeter(len)];
	ft_memdel((void *)&array);
	return (mediana);
}


void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

size_t		dilimeter(size_t len)
{
	if (len)
		return (len / 2 - (!(len % 2)));
	return (0);
}

void		quick_sort(int32_t *array, int32_t len_l, int32_t len_h)
{
	int32_t	index_l;
	int32_t	index_r;
	int32_t	piv;

	index_r = len_h;
	index_l = len_l;
	piv = array[(index_l + index_r) / 2];
	while (index_l <= index_r)
	{
		while (array[index_l] < piv)
			index_l++;
		while (array[index_r] > piv)
			index_r--;
		if (index_l <= index_r)
		{
			swap(&array[index_l], &array[index_r]);
			index_l++;
			index_r--;
		}
	}
	if (len_l < index_r)
		quick_sort(array, len_l, index_r);
	if (len_h > index_l)
		quick_sort(array, index_l, len_h);
}
