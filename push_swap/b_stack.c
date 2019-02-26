/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:38:21 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/26 19:59:30 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

size_t	b_top(t_stack **a, t_stack **b, size_t *len_top, size_t *len_bot)
{
	size_t  len_a;
	int32_t	mediana;

	len_a = 0;
	mediana = find_mediana_for_block(*b, *len_top);
	if (*len_top <= MIN_STACK_LEN)
	{
		while (*len_top)
		{
			op_pa(a, b);
			(*len_top)--;
		}
		sort(a);
	}
	while (*len_top)
	{
		if ((*b)->value < mediana)
		{
			op_rb(NULL, b);
			(*len_bot)++;
		}
		else if ((*b)->value >= mediana)
		{
			op_pa(a, b);
			len_a++;
		}
		(*len_top)--;
	}
//	if (len_a > MIN_STACK_LEN)
//	{
//		sort_a_top();
//	}
	return (len_a);
}

//TODO самые хуевые элемены в топе стека б а выше медианы в топ стека а

void	b_bot(t_stack **a, t_stack **b, size_t *len_bot, size_t *len_top)
{
	int32_t mediana;

	if (*len_bot <= MIN_STACK_LEN)
	{
		while (*len_bot)
		{
			op_rrb(NULL, b);
			op_pa(a, b);
			(*len_bot)--;
		}
		sort(a);
	}
	else if (*len_bot > MIN_STACK_LEN)
	{
		mediana = find_mediana_for_block(search_elem(*b, *len_bot),
										 *len_bot);
		while (*len_bot)
		{
			if ((*b)->prev->value < mediana)
			{
				op_rrb(NULL, b);
				(*len_top)++;
				(*len_bot)--;
			}
			else
			{
				op_rrb(NULL, b);
				op_pa(a, b);
				(*len_bot)--;
			}
		}
		sort(a);
	}
}
