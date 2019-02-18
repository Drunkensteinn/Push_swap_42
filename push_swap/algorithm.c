/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:56:12 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/16 22:13:19 by ablizniu         ###   ########.fr       */
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
		if ((*a)->value <= mediana)
		{
			op_pb(a, b);
			(*elem)++;
		}
		else
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
	else if (stack_len == 1)
		return (*block);
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


void	sort_top_of_a(t_stack **a, t_stack **b, int32_t *len)
{
	while (*len)
	{
		op_pa(a, b);
		(*len)--;
	}
	sort(a, true);
}

void	working_with_the_understack(t_stack **a, t_stack **b, int32_t *len_under_stack, int32_t *block_len)
{
	t_stack *iterator;
	size_t	i;
	int32_t under_stack_mediana;
	size_t	pushed;

	pushed = 0;
	while(*len_under_stack)
	{
		if (*len_under_stack < MIN_STACK_LEN)
		{
			op_rrb(a, b);
			op_pa(a, b);
			(*len_under_stack)--;
			(*block_len)--;
		}
		else
		{
			i = 0;
			iterator = *b;
			while (*len_under_stack > i)
			{
				iterator = iterator->prev;
				i++;
			}
			under_stack_mediana = find_mediana_for_block(init_array(*len_under_stack, iterator), *len_under_stack);
			while (pushed < MIN_STACK_LEN)
			{
				while ((*b)->value < under_stack_mediana)
				{
					op_rrb(NULL, b);
					(*len_under_stack)--;
				}
				op_pa(a, b);
				(*block_len)--;
				pushed++;
			}
		}
	}
	sort(a, false);
}

//TODO u need to search mediana from both sides - top and end of the stack - economy of operations and complete work of algo

void	sort_the_b_blocks(t_stack **a, t_stack **b, int32_t *len)
{
	int32_t *block;
	int32_t iterator;
	int32_t mediana;
	int32_t under_stack;

	iterator = 0;
	under_stack = 0;
	block = init_array(*len, *b);
	mediana = find_mediana_for_block(block, *len);
	while (*b && iterator < MIN_STACK_LEN)
	{
		if ((*b)->value >= mediana)
		{
			op_pa(a, b);
			iterator++;
			(*len)--;
		}
		else
		{
			op_rb(a, b);
			under_stack++;
		}
	}
	sort(a, true);
	working_with_the_understack(a, b, &under_stack, len);
	ft_memdel((void *) &block);
	if (*len > MIN_STACK_LEN)
		sort_the_b_blocks(a, b, len);

}

void	algorithm(t_stack **a, t_stack **b, int32_t *stack_map, size_t pos)
{
	while (stack_map[pos])
	{
		if (stack_map[pos] > MIN_STACK_LEN)
			sort_the_b_blocks(a, b, &stack_map[pos]);
		else
			sort_top_of_a(a,b,&stack_map[pos]);
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
	ft_putchar('\n');
}