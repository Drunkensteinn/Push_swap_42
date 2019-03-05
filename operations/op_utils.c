/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 21:00:34 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 22:12:39 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

inline size_t	stack_length(t_stack *stack)
{
	t_stack	*iterator;
	size_t	len;

	len = 0;
	iterator = stack;
	iterator = iterator->next;
	while (iterator->head != true)
	{
		iterator = iterator->next;
		len++;
	}
	return (len + 1);
}

t_stack		*pop(t_stack **stack)
{
	t_stack *head;

	head = *stack;
	(*stack)->head = false;
	*stack = (*stack)->next;
	(*stack)->head = true;
	(*stack)->prev = head->prev;
	(*stack)->prev->next = *stack;
	head->prev = NULL;
	head->next = NULL;
	if (!(*stack)->next && !(*stack)->prev)
		*stack = NULL;
	return (head);
}

void		push(t_stack **stack, t_stack *elem, t_bool is_head)
{
	t_stack *head;

	head = (*stack);
	if (head && elem)
	{
		(*stack)->head = false;
		elem->next = head;
		elem->prev = head->prev;
		head->prev->next = elem;
		head->prev = elem;
		*stack = elem;
		(*stack)->head = is_head;
	}
	else if (elem)
	{
		(*stack) = elem;
		(*stack)->head = is_head;
		(*stack)->next = (*stack);
		(*stack)->prev = (*stack);
	}
}

void	add_operation(t_command **list, char *name)
{
	t_command *current;

	if (*list)
	{
		current = *list;
		(*list)->command = ft_strdup(name);
		if (!(*list)->next)
			(*list)->next = (t_command *)ft_memalloc(sizeof(t_command));
		(*list) = (*list)->next;
		(*list)->prev = current;
	}
}