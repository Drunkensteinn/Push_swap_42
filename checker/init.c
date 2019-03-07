/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:11:23 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/25 20:14:15 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *init_elem(void)
{
	t_stack		*stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	return (stack);
}
