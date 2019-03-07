/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:01:16 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 16:36:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int32_t argc, const char **argv)
{
	t_stack		*a;
	t_command	*command;
	char		**argument;
	int32_t		argument_len;

	argument = (char **)&argv[1];
	argument_len = argc - 1;
	if (argument_len >= 1)
	{
		if (argument_len == 1 && (!(argument = validate_single_array(*argument,
				&argument_len)) || !array_validation(argument_len, argument)))
			print_error(INVALID_DATAS_ERROR);
		else
			if (!array_validation(argument_len, argument))
				print_error(INVALID_DATAS_ERROR);
		a = init_the_stack(argument_len, argument);
		if ((validate_duplication(a)))
			print_error(DUPLICATION_ERROR);
		if (!sort_status_check(a))
			command = algorithm_body(a, NULL);
	}
	return  (0);
}
