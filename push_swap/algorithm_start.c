/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:55:40 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 16:30:29 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/op.h"

t_command *algorithm_start(t_stack **a, t_stack **b, const int32_t *map,
							size_t len)
{
	t_command	*head;
	size_t		elem;

	if (!(head = (t_command *)ft_memalloc(sizeof(t_command))))
		print_error(NULL);
	while (b && len)
	{
		elem = (size_t)map[len - 1];
		main_sort_algorithm(a, b, &elem, &head);
		len--;
	}
	return (head);
}

t_command *algorithm_body(t_stack *a, t_stack *b)
{
	t_command	*command_head;
	t_command	*command_body;
	int32_t		*map;
	size_t		len_map;

	len_map = 0;
	command_body = NULL;
	if (!(command_head = (t_command *)ft_memalloc(sizeof(t_command))))
		print_error(NULL);
	if (!three_step_sort(a, &command_head))
	{
		map = init_map(stack_length(a), &len_map);
		pre_sorting(&a, &b, map, &command_head);
		command_body = algorithm_start(&a, &b, map, len_map);
		ft_memdel((void *)&map);
	}
	command_body = iterate(command_body);
	command_head = cmd_lstcat(&command_body, command_head);
	output_commands(command_head);
	return (command_head);

}