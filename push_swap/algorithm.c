/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:56:12 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/26 16:45:41 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../operations/op.h"

t_stack *search_elem(t_stack *stack, size_t len)
{
	size_t	i;
	t_stack *iterator;

	i = 0;
	iterator = stack;
	while (len > i)
	{
		iterator = iterator->prev;
		i++;
	}
	return (iterator);
}

int32_t find_mediana_for_top_and_bot(t_stack **b, const size_t *len_bot, const size_t *len_top)
{
	int32_t *array;
	t_stack *iterator;
	size_t	i;

	i = 0;
	iterator = search_elem(*b, *len_bot);
	array = init_array(*b, (*len_bot + *len_top));
	while (i < *len_bot)
	{
		array[i + *len_top] = iterator->value;
		iterator = iterator->next;
		i++;
	}
	quick_sort(array , 0, (int32_t)((*len_bot + *len_top) - 1));
	return (array[(*len_bot + *len_top)] / 2);
}

t_bool bot_or_top(t_stack **b, size_t len_top, size_t len_bot, int32_t mediana)
{
	t_stack *top;
	t_stack *bot;
	size_t 	counter_top;
	size_t 	counter_bot;

	counter_bot = 0;
	counter_top = 0;
	bot = search_elem(*b, (size_t)len_bot);
	top = *b;
	while (len_top)
	{
		if (top->value >= mediana)
			counter_top++;
		top = top->next;
		len_top--;
	}
	while (len_bot)
	{
		if (bot->value >= mediana)
			counter_bot++;
		bot = bot->next;
		len_bot--;
	}
	return (counter_top > counter_bot ? (2) : (1));
}

size_t	sort_a_bot(t_stack **a, t_stack **b, size_t *len_of_bot, size_t *len_of_top)
{
	int32_t	mediana;
	size_t	top_b;

	top_b = 0;
	if (*len_of_bot <= MIN_STACK_LEN)
	{
		while (*len_of_bot)
		{
			op_rra(a, NULL);
			(*len_of_bot)--;
			(*len_of_top)++;
		}
	}
	else if (*len_of_bot > MIN_STACK_LEN)
	{
		mediana = find_mediana_for_block(search_elem(*a, *len_of_bot),
				*len_of_bot);
		while (*len_of_bot)
		{
			if ((*a)->prev->value < mediana)
			{
				op_rra(a, NULL);
				op_pb(a, b);
				top_b++;
			}
			else
			{
				op_rra(a, NULL);
				(*len_of_top)++;
			}
			(*len_of_bot)--;
		}
	}
	sort(a);
	return (top_b);
}



size_t	sort_a_top(t_stack **a, t_stack **b, size_t *len_top_b, size_t *len_a_top)
{
	int32_t mediana;
	size_t	len_a_bot;

	len_a_bot = 0;
	mediana = find_mediana_for_block(*a, *len_a_top);
	if (*len_a_top && *len_a_top <= MIN_STACK_LEN)
	{
		sort(a);
		*len_a_top = 0;
	}
	else if (*len_a_top && *len_a_top > MIN_STACK_LEN)
		while (*len_a_top)
		{
			if ((*a)->value < mediana)
			{
				op_pb(a, b);
				(*len_top_b)++;
			}
			else
			{
				op_ra(a, NULL);
				len_a_bot++;
			}
			(*len_a_top)--;
		}
	if (len_a_bot)
		*len_top_b += sort_a_bot(a, b, &len_a_bot, len_a_top);
	if (*len_a_top)
		sort_a_top(a, b, len_top_b, len_a_top);
	return (*len_top_b);
}

void	main_sort_algorithm(t_stack **a, t_stack **b, size_t *unsorted_elems)
{
	size_t	len_of_top;
	size_t	len_of_bot;
	size_t	len_a;
	int32_t	mediana;

	len_a = 0;
	len_of_bot = 0;
	len_of_top = (size_t)*unsorted_elems;
	if (*unsorted_elems <= MIN_STACK_LEN)
		sort_min_stack_len_and_push(a, b, unsorted_elems);
	else if (*unsorted_elems > MIN_STACK_LEN)
	{
		len_a = b_top(a,b, &len_of_top, &len_of_bot);
		len_of_bot = (*unsorted_elems) - len_a;
		if (len_a)
			len_of_top = sort_a_top(a, b, &len_of_top, &len_a);
		if (len_of_top)
			len_a = b_top(a, b, &len_of_top, &len_of_bot);
		if (len_of_bot)
			b_bot(a, b, &len_of_bot, &len_of_top);
		*unsorted_elems = len_of_top + len_of_bot;
	}
	if (*unsorted_elems)
		main_sort_algorithm(a, b, unsorted_elems);
}

//TODO  сделай так чтобы сначала полностью стек а прорабатывался, должно остаться 6 элементов : 3 сверху - сортируешь и 3 снизу сортируешь

void	algorithm_start(t_stack **a, t_stack **b, int32_t *map, size_t len)
{
	while (b && len)
	{
		main_sort_algorithm(a, b, (size_t *)&map[INDEX(len)]);
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
	sort(&a);
	algorithm_start(&a, &b, map, len_map);
	print_stack(a, 100);
}