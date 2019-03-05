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

void			write_in_mediana(t_stack *stack, size_t len, int32_t mediana)
{
	t_stack *iterator;
	size_t i;

	i = 0;
	iterator = stack;
	while (iterator && i < len)
	{
		stack->mediana = mediana;
		stack = stack->next;
		i++;
	}
}

t_bool			push_or_not_to_push(t_stack *stack, int64_t mediana, const size_t *len, t_bool direction)
{
	size_t iter;
	t_stack *iterator;

	iter = 0;
	iterator = stack;
	while (iter < *len)
	{
		if (direction && iterator->value > mediana)
			return (true);
		if (!direction && iterator->value <= mediana)
			return (true);
		iterator = iterator->next;
		iter++;
	}
	return (false);
}

void _a_push_bot_and_to_top(t_stack **a, t_stack **b, size_t *len, t_command **list)
{
	size_t under;

	under = 0;
	while (push_or_not_to_push(*a, (*a)->mediana, len, false))
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


void _b_push_bot_and_to_top(t_stack **a, t_stack **b, size_t *len, t_command **list)
{
	size_t under;
	size_t buff;

	under = 0;
	buff = *len;
	while (push_or_not_to_push(*b, (*b)->mediana, len, true))
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
	while (under)
	{
		if ((buff / 2 == stack_length(*b)) && !push_or_not_to_push(search_elem(*b, under), search_elem(*b, under)->mediana, &under, true))
			return;
		else if (buff == under && !push_or_not_to_push(search_elem(*b, under), search_elem(*b, under)->mediana, &under, true))
			return;
		else if (under == stack_length(*b) && !push_or_not_to_push(search_elem(*b, under), search_elem(*b, under)->mediana, &under, true))
			return;
		else if (under == stack_length(*b) - 1 && !push_or_not_to_push(search_elem(*b, under), search_elem(*b, under)->mediana, &under, true))
			return;
		else if (under > stack_length(*b) / 2 && !push_or_not_to_push(search_elem(*b, under), search_elem(*b, under)->mediana, &under, true))
			return;
		op_rrb(NULL, b, list);
		under--;
	}
	//}
}

void solution_b(t_stack **a, t_stack **b, size_t *elems, t_command **list)
{
	while (*b && *elems && (*b)->value + 1 == (*a)->value)
	{
		op_pa(a, b, list);
		(*a)->mediana = MARKED;
		(*elems)--;
	}
}

void solution_a(t_stack **a, t_stack **b, t_command **list)
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
	if (*b && *elems_in_b && *elems_in_b <= MIN_ELEMS)
		push_and_sort(a, b, elems_in_b, list);
	else if (*b && *elems_in_b && *elems_in_b)
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

t_command *algorithm_start(t_stack **a, t_stack **b, int32_t *map,
							size_t len)
{
	t_command *head;

	if (!(head = (t_command *)ft_memalloc(sizeof(t_command))))
		exit(0);
	while (b && len)
	{
		main_sort_algorithm(a, b, (size_t *) &map[INDEX(len)], &head);
		len--;
	}
	return (head);
}

t_command	*iterate(t_command *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	cmd_lstcat(t_command *from, t_command *to)
{
	to->next = from;
	to = iterate(to);
	optimize_commands(to);
	while (to)
	{
		ft_putendl(to->command);
		to = to->next;
	}
}

void	remove_and_add(t_command *l1, t_command *l2, char *name)
{
	t_command *tmp1;

	tmp1 = l2;
	l1->next = l2->next;
	l2->next->prev = l1;
	l1->command = name;
	ft_memdel((void *)&tmp1);

}

void	optimize_commands(t_command *lst)
{
	while (lst)
	{
		if (lst->command == RA && lst->next->command == RB)
			remove_and_add(lst, lst->next, RR);
		if (lst->command == SA && lst->next->command == SB)
			remove_and_add(lst, lst->next, SS);
		if (lst->command == RRA && lst->next->command == RRB)
			remove_and_add(lst, lst->next, RRR);
		lst = lst->next;
	}
}

void algorithm_init(t_stack *a, t_stack *b)
{
	t_command	*command_head;
	t_command	*command_body;
	int32_t		*map;
	size_t		len_map;

	len_map = 0;
	if (!(command_head = (t_command *)ft_memalloc(sizeof(t_command))))
		exit(0);
	map = init_map(stack_length(a), &len_map);
	pre_sorting(&a, &b, map, &command_head);
	command_body = algorithm_start(&a, &b, map, len_map);
	cmd_lstcat(iterate(command_body), command_head);
//	print_stack(a, 100);
}