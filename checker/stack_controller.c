/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:14:45 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/27 22:06:20 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			create_new_elem(t_stack **lst, t_stack *prev, int32_t elem)
{
	if (!*lst)
	{
		if (!(*lst = (t_stack *)ft_memalloc(sizeof(t_stack))))
			return;
	}
	(*lst)->value = elem;
	(*lst)->prev = prev;
}

inline void		check_created_elem(t_stack **stack, t_stack *prev,
				char **data, size_t index)
{
	if (data)
	{
		if (ft_isint(data[index], true))
			create_new_elem(stack, prev, ft_atoi(data[index]));
		else
			print_error();
	}
	else
		create_new_elem(stack, prev, 0);
}

t_stack			*init_the_stack(int32_t num, char **value)
{
	t_stack		*stack;
	t_stack		*temp;
	size_t		i;

	i = 1;
	stack = init_elem();
	temp = stack;
	check_created_elem(&stack, NULL, value, 0);
	while (i < (size_t)num)
	{
		check_created_elem(&temp->next, temp, value, i);
		temp = temp->next;
		i++;
	}
	temp->next = stack;
	stack->prev = temp;
	return  (stack);
}
