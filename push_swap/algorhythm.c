/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorhythm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:06:34 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/07 14:23:49 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algorhythm(int32_t *array, size_t len)
{
	int32_t mediana;
	int32_t *temp;


	temp = ft_arrdup(array, len);
	mediana = search_mediana(temp, len);
	ft_memdel((void *)&temp);
}

int32_t		*ft_arrdup(const int32_t *dst, size_t len)
{
	int		*ptr;
	size_t	index;

	index = 0;
	if (!(ptr = (int *)ft_memalloc(sizeof(int) * len + 1)))
		return (NULL);
	while (index < len)
	{
		ptr[index] = dst[index];
		index++;
	}
	return  (ptr);
}

int32_t		supporting_element(int32_t len)
{
	return  (len / 2 + (len % 2));
}

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sorting(int32_t **start, int32_t **end, const int32_t pivot)
{
	while (start && end)
	{
		if (**start >= pivot && **end <= pivot)
			swap(*start, *end);
		if (**start < pivot)
			(*start)++;
		if (**end > pivot)
			(*end)--;
		if (*start >= *end)
			break ;
	}
}

int32_t search_mediana(int32_t *array, size_t len)
{
	int32_t mediana;
	int32_t	sup_elem;

	sup_elem = supporting_element((int32_t)len);
	mediana = rec_search(array, array + len,len, sup_elem);
	return (0);
}

int32_t		rec_search(int32_t *start, int32_t *end, size_t len, int32_t supp_elem)
{
	int32_t		pivot;
	int32_t		mediana;

	pivot = start[(int)RANDOM_INDEX(len)];
	sorting(&start, &end, pivot);
	if (!supp_elem)
		return (*start);
	if (end - start + 1 <= supp_elem)
	{
		supp_elem -= end - start + 1;
		mediana = rec_search();
	}
	else
		mediana = rec_search();
	return (mediana);
	//sorting()//ДОПИСАТЬ!
}