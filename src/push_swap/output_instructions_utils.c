/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_instructions_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:32:03 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 22:00:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_command	*iterate(t_command *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}

void	output_commands(t_command *lst)
{
	t_command *iterator;

	iterator = lst;
	while (iterator)
	{
		print_op(iterator->command);
		ft_strdel(&iterator->command);
		iterator = iterator->next;
	}
}

t_command	*cmd_lstcat(t_command **from, t_command *to)
{
	t_command *tmp;

	if (to)
	{
		if (from && *from)
		{
			tmp = to;
			to->prev->next = *from;
			(*from)->prev = (to)->prev;
			to = (to)->prev;
			ft_memdel((void *)&tmp);
		}
		to = iterate(to);
		optimize_commands(to);
	}
	return (to);
}

t_command	*remove_and_add(t_command *l1, t_command *l2, char *name)
{
	t_command *tmp1;

	tmp1 = l2;
	l1->next = l2->next;
	l2->next->prev = l1;
	ft_strcpy(l1->command, name);
	ft_strdel(&tmp1->command);
	ft_memdel((void *)&tmp1);
	return (l1);
}

t_command	*remove_permanently(t_command *iterator)
{
	t_command *temp1;
	t_command *temp2;

	temp1 = (iterator);
	temp2 = (iterator)->next;
	(iterator)->prev->next = (iterator)->next->next;
	(iterator)->next->next->prev = (iterator)->prev;
	iterator = iterator->prev;
	ft_strdel(&temp1->command);
	ft_strdel(&temp2->command);
	ft_memdel((void *)&temp1);
	ft_memdel((void *)&temp2);
	return (iterator);
}