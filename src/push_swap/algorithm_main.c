/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:48:37 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/06 19:19:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/op.h"

static void _a_push_bot_and_to_top(t_stack **a, t_stack **b, size_t *len, t_command **list)
{
	size_t under;

	under = 0;
	while (is_push(*a, (*a)->mediana, len, false))
	{
		if ((*a)->value <= (*a)->mediana)
			op_pb(a, b, list);
		else
		{
			op_ra(a, NULL, list);
			under++;
		}
		(*len)--;
	}
	*len = under;
	while (under)
	{
		op_rra(a, NULL, list);
		under--;
	}
}

static void _b_push_bot_and_to_top(t_stack **a, t_stack **b, size_t *len, t_command **list)
{
	size_t under;
	size_t buff;

	under = 0;
	buff = *len;
	while (*b && is_push(*b, (*b)->mediana, len, true))
	{
		if ((*b)->value > (*b)->mediana)
			op_pa(a, b, list);
		else
		{
			op_rb(NULL, b, list);
			under++;
		}
		(*len)--;
	}
	*len = under;
	if (*b)
		if (_b_condition(b, under, buff))
			return ;
	while (*b && under)
	{
		op_rrb(NULL, b, list);
		under--;
	}
}

static void solution_a(t_stack **a, t_stack **b, t_command **list)
{
	size_t len;

	len = block_len(*a);;
	while (len > MIN_ELEMS)
	{
		write_in_mediana(*a, len, search_mediana(init_array(*a, len), len));
		_a_push_bot_and_to_top(a, b, &len, list);
		len = block_len(*a);
	}
	sort(a, list);
}

void main_sort_algorithm(t_stack **a, t_stack **b, size_t *elems_in_b,
						 t_command **list)
{
	if (*b && *elems_in_b <= MIN_ELEMS)
		push_and_sort(a, b, elems_in_b, list);
	else if (*b && *elems_in_b >= MIN_ELEMS)
	{
		if (*elems_in_b)
		{
			write_in_mediana(*b, *elems_in_b, search_mediana(init_array(*b, *elems_in_b), *elems_in_b));
			_b_push_bot_and_to_top(a, b, elems_in_b, list);
			solution_a(a, b, list);
		}
	}
	if (*b && (*elems_in_b = block_len(*b)))
		main_sort_algorithm(a, b, elems_in_b, list);
}
