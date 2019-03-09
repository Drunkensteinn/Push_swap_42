/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:12:21 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 22:27:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/op.h"

t_bool			three_step_sort(t_stack *a, t_command **list)
{
	if (stack_length(a) <= MIN_ELEMS)
	{
		while (!condition_for_sort(a))
		{
			if (a->value > a->prev->value)
				op_ra(&a, NULL, list);
			else if (a->value > a->next->value)
				op_sa(&a, NULL, list);
			else if (a->next->value > a->next->next->value)
			{
				op_ra(&a, NULL, list);
				op_sa(&a, NULL, list);
				op_rra(&a, NULL, list);
			}
		}
		return (true);
	}
	return (false);
}

void			pre_sorting(t_stack **a, t_stack **b,
				int32_t *map, t_command **command)
{
	int32_t		mediana;
	size_t		len;
	size_t		i;

	i = 0;
	len = stack_length(*a);
	while (len > MIN_ELEMS)
	{
		mediana = search_mediana(init_array(*a, len), len);
		map[i] = pushing_by_mediana(a, b, mediana, command);
		len = stack_length(*a);
		i++;
	}
	sort(a, command);
}

void			sort(t_stack **stack_a, t_command **list)
{
	while (!condition_for_sort(*stack_a))
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			op_sa(stack_a, NULL, list);
		else if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			op_ra(stack_a, NULL, list);
			op_sa(stack_a, NULL, list);
			op_rra(stack_a, NULL, list);
		}
	}
	mark(*stack_a);
}

void			push_and_sort(t_stack **a, t_stack **b,
				size_t *len, t_command **list)
{
	while (*len)
	{
		op_pa(a, b, list);
		(*len)--;
	}
	sort(a, list);
}
