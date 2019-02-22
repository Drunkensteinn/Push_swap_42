/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:12:21 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/22 17:50:37 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

void	pre_sorting(t_stack **a, t_stack **b, int32_t *map ,int32_t len)
{
	int32_t		mediana;
	size_t		length;
	int32_t		elem;

	elem = 0;
	mediana = search_mediana(init_array((int32_t)len, *a), (size_t)(len));
	pushing_by_mediana(a, b, mediana, &elem);
	length = stack_length(*a);
	*map = elem;
	if (length > MIN_STACK_LEN)
		pre_sorting(a, b, map + 1, (int32_t)length);
}

int32_t find_mediana_for_block(int32_t *block, int32_t stack_len)
{
	int32_t mediana;

	mediana = 0;
	if (stack_len && stack_len >= MIN_STACK_LEN)
	{
		quick_sort(block, 0, (int32_t)(stack_len - 1));
		mediana = block[(int32_t)(stack_len - MIN_STACK_LEN)];
	}
	else if (stack_len == 2)
		mediana = (*block > *(block + 1)) ? (*(block + 1)) : (*block);
	else if (stack_len == 1)
		mediana = *block;
	ft_memdel((void *)&block);
	return (mediana);
}

void sort(t_stack **stack_a, t_bool is_asscending)//убрать потом
{
	while(!condition_for_sort(*stack_a))
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			op_sa(stack_a, NULL);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			op_ra(stack_a, NULL);
			op_sa(stack_a, NULL);
			op_rra(stack_a, NULL);
		}
	}
}

void	sort_min_stack_len_and_push(t_stack **a, t_stack **b, int32_t *len)
{
	while (*len)
	{
		op_pa(a, b);
		(*len)--;
	}
	sort(a, true);
}
