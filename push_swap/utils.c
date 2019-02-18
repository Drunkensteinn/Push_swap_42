/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:01:28 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/15 17:56:28 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack, size_t size)
{
	t_stack	*iterator;
	size_t	len;

	len = 0;
	iterator = stack;
	ft_putnbr(iterator->value);
	ft_putchar(' ');
	len++;
	iterator = iterator->next;
	while (iterator && len < size)
	{
		ft_putnbr(iterator->value);
		ft_putchar(' ');
		iterator = iterator->next;
		len++;
		if (iterator->head)
			break ;
	}
}