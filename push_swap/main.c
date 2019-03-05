/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:01:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/08 13:00:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool		array_validation(int32_t len, char **array)
{
	size_t i;

	i = 0;
	while (i < (size_t)len)
	{
		if (!ft_isint(array[i], false))
			return (false);
		i++;
	}
	return (true);
}

int main(int32_t argc, char **argv)
{
	if (argc >= 2)
	{
		if (!array_validation(argc - 1, &argv[1]))
			print_error();
		algorithm_init(init_the_stack(argc - 1, &argv[1]), NULL);
	}
	else
		print_error();
	return  (0);
}