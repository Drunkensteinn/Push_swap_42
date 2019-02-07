/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:01:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/03 20:07:38 by ablizniu         ###   ########.fr       */
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
	int32_t		*operational_array;

	if (argc >= 2)
	{
		if (!array_validation(argc - 1, &argv[1]))
			print_error();
		operational_array = init_array(argc - 1, &argv[1]);
		algorhythm(operational_array, (size_t)(argc - 1));
	}
	else
		print_error();
	return  (0);
}