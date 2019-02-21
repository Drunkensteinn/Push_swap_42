/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:56:12 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/21 21:39:27 by ablizniu         ###   ########.fr       */
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
	array = init_array((int32_t)(*len_bot + *len_top), *b);
	while (i < *len_bot)
	{
		array[i + *len_top] = iterator->value;
		iterator = iterator->next;
		i++;
	}
	return (find_mediana_for_block(array, (int32_t)(*len_bot + *len_top)));
}

t_bool len_or_top(t_stack **b, size_t len_top, size_t len_bot, int32_t mediana)
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

void	working_with_the_understack(t_stack **a, t_stack **b, size_t *len_bot, size_t *len_top)
{
	int32_t under_stack_mediana;
	size_t	pushed;
	int32_t	pos;

	pushed = 0;
	pos = 0;
	if (*len_bot < MIN_STACK_LEN && *len_top < MIN_STACK_LEN)
	{
		while (*len_bot)
		{
			op_rrb(a, b);
			op_pa(a, b);
			(*len_bot)--;
		}
	}
	else
	{
		under_stack_mediana = find_mediana_for_top_and_bot(b, len_bot, len_top);
		while (pushed < MIN_STACK_LEN)
		{
			if ((*len_bot || *len_top) || (*len_bot && *len_top))
				pos = len_or_top(b, *len_top, *len_bot, under_stack_mediana);
			if (*len_top && pos == TOP)
			{
				while (*b && *len_top && pushed < MIN_STACK_LEN)
				{
					if ((*b)->value >= under_stack_mediana)
					{
						op_pa(a,b);
						pushed++;
					}
					else
					{
						op_rb(NULL, b);
						(*len_bot)++;
					}
					(*len_top)--;
				}
			}
			if (*len_bot && pos == BOT)
			{
				while (*b && *len_bot && pushed < MIN_STACK_LEN)
				{
					if ((*b)->prev->value >= under_stack_mediana)
					{
						op_rrb(NULL, b);
						op_pa(a, b);
						pushed++;
					}
					else
					{
						op_rrb(NULL, b);
						(*len_top)++;
					}
					(*len_bot)--;
				}
			}
		}
	}
	sort(a, false);
	if (*len_bot >= MIN_STACK_LEN || *len_top >= MIN_STACK_LEN)
		working_with_the_understack(a, b, len_bot, len_top);
}

void	main_sort_algorithm(t_stack **a, t_stack **b, int32_t *number_of_elems)
{
	size_t	len_of_top;
	size_t	len_of_bot;
	size_t	iterator;
	int32_t	mediana;

	iterator = 0;
	len_of_bot = 0;
	len_of_top = (size_t)*number_of_elems;
	mediana = find_mediana_for_block(init_array(*number_of_elems, *b), *number_of_elems);
	while (*b && iterator < MIN_STACK_LEN)
	{
		if ((*b)->value >= mediana)
		{
			op_pa(a, b);
			iterator++;
			len_of_top--;
			(*number_of_elems)--;
		}
		else
		{
			op_rb(a, b);
			len_of_top--;
			len_of_bot++;
		}
	}
	sort(a, true);
	if (len_of_bot)
		working_with_the_understack(a, b, &len_of_bot, &len_of_top);
	if (len_of_bot < MIN_STACK_LEN || len_of_top < MIN_STACK_LEN)
		push_top_and_bot(a, b, &len_of_bot, &len_of_top);
	*number_of_elems = (int32_t)(len_of_bot + len_of_top);
	if (*number_of_elems > MIN_STACK_LEN)
		main_sort_algorithm(a, b, number_of_elems);
}

void	push_top_and_bot(t_stack **a, t_stack **b, size_t *len_bot, size_t *len_top)
{
	while (*len_bot)
	{
		op_rrb(NULL, b);
		op_pa(a, b);
		(*len_bot)--;
	}
	while (*len_top)
	{
		op_pa(a, b);
		(*len_top)--;
	}
	sort(a, true);
}

void	algorithm(t_stack **a, t_stack **b, int32_t *stack_map, size_t pos)
{
	while (stack_map[pos])
	{
		if (stack_map[pos] > MIN_STACK_LEN)
			main_sort_algorithm(a, b, &stack_map[pos]);
		else
			sort_min_stack_len_and_push(a, b, &stack_map[pos]);
	}
}

void	algorithm_start(t_stack **a, t_stack **b, int32_t *map, size_t len)
{
	while (b && len)
	{
		algorithm(a, b, map, INDEX(len));
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
	sort(&a, true);
	algorithm_start(&a, &b, map, len_map);
	print_stack(a, 100);
}