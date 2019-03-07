/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:53:30 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/07 20:43:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int32_t argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int32_t		argument_len;
	char		**argument;

	stack_a = NULL;
	stack_b = NULL;
	argument = (char **)&argv[1];
	argument_len = argc - 1;
	if (argc >= 2)
	{
		if (argument_len == 1 && (!(argument = validate_single_array(*argument,
				&argument_len)) || !array_validation(argument_len, argument)))
			print_error(INVALID_DATAS_ERROR);
		else
			if (!array_validation(argument_len, argument))
				print_error(INVALID_DATAS_ERROR);
		stack_a = init_the_stack(argument_len, argument);
		if ((validate_duplication(stack_a)))
			print_error(DUPLICATION_ERROR);
		execute_operations(&stack_a, &stack_b);
		print_status(stack_a);
	}
	return (0);
}