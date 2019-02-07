/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:10:29 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/03 21:57:11 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_op(const char *op)
{
	ft_putendl(op);
}

void	print_error(void)
{
	ft_putstr("you have insert a shit!\n");
	exit(0);
}

void		print_array(int32_t *array, size_t	len)
{
	size_t i = 0;

	while (i < len)
	{
		ft_putnbr(array[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}