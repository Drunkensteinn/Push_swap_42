/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:12:21 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 20:23:58 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

void pre_sorting(t_stack **a, t_stack **b, int32_t *map, t_command **command)
{
	int32_t		mediana;
	size_t		len;
	size_t 		i;

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

void sort(t_stack **stack_a, t_command **list)
{
	while(!condition_for_sort(*stack_a))
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

void push_and_sort(t_stack **a, t_stack **b, size_t *len, t_command **list)
{
	while (*len)
	{
		op_pa(a, b, list);
		(*len)--;
	}
	sort(a, list);
}
