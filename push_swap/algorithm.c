/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:56:12 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/11 22:50:04 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

inline t_bool	condition_for_push(t_stack *stack, int32_t value)
{
	t_stack *iterator;

	iterator = stack;
	iterator = iterator->next;
	while (iterator)
	{
		if (iterator->value < value)
			return (false);
		if (iterator->head == true)
			break ;
		iterator = iterator->next;
	}
	return (true);
}

void		pushing_by_mediana(t_stack **a, t_stack **b, int32_t mediana,
							   int32_t *elem)
{
	while (!(condition_for_push(*a, mediana)))
	{
		if ((*a)->value < mediana)
		{
			print_op(PB);
			op_pb(a, b);
			(*elem)++;
			continue ;
		}
		print_op(RA);
		op_ra(a, b);
	}
}

inline t_bool	condition_for_sort(t_stack *stack)
{
	t_stack *iterator;

	iterator = stack;
	while (iterator->next->head != true)
	{
		if (iterator->value > iterator->next->value)
			return (false);
		iterator = iterator->next;
	}
	return (true);
}


t_stack	*sort_asscending(t_stack *stack)//убрать потом
{
	while (!condition_for_sort(stack))
	{
		if (stack->value < stack->next->value)
		{
			op_sa(&stack, NULL);
			continue ;
		}
		op_ra(&stack, NULL);
	}
	return (stack);
}

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
	if (length >= MIN_STACK_LEN)
		pre_sorting(a, b, map + 1, (int32_t)length);
}

t_stack *choose_elem(t_stack **stack_b, int32_t *number_of_elems)
{
	int32_t		mediana;

	if (*number_of_elems >= 2)
	{
		mediana = search_mediana(init_array(*number_of_elems, *stack_b), (size_t)*number_of_elems);
		while (*number_of_elems)
		{
			if ((*stack_b)->value > mediana)
				return (choose_elem(stack_b, number_of_elems));
			else
				op_rb(NULL, stack_b);
			(*number_of_elems)--;
		}
	}
	else
	{
		(*number_of_elems)--;
		return (*stack_b);
	}
	return (NULL);
}

void	algorithm(t_stack **a, t_stack **b, int32_t *stack_map, size_t pos)
{
	while (stack_map[INDEX(pos)])
	{
		*b = choose_elem(b, &stack_map[INDEX(pos)]);
		op_pa(a, b);
	}
}

void	algorithm_start(t_stack *a, t_stack *b, int32_t *map, size_t len)
{
	while (b && INDEX(len) > 0)
	{
		algorithm(&a, &b, map, len);
		len--;
	}
}


void	algorithm_init(t_stack *a, t_stack *b, int32_t argc)
{
	int32_t *map;
	size_t	len_map;

	len_map = 0;
	map = init_map(stack_length(a), &len_map);
	pre_sorting(&a, &b, map, argc);
	algorithm_start(sort_asscending(a), b, map, len_map);
}