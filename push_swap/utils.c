/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:01:28 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/10 19:34:33 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*iterator;
	size_t	len;

	len = 0;
	iterator = stack;
	printf("value -  %d index - %zu \n", iterator->value, len);
	len++;
	iterator = iterator->next;
	while (iterator)
	{
		printf("value -  %d index - %zu \n", iterator->value, len);
		iterator = iterator->next;
		len++;
		if (iterator->head)
			break ;
	}
}