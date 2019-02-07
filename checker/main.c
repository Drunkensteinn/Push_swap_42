/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:53:30 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/30 18:57:41 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool	validation_of_array(char *array)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(array))
	{
		if (!ft_isdigit(array[i]))
			return (false);
		i++;
	}
	return (true);
}


t_bool validation_of_list(int32_t len, char **stack)
{
	size_t  i;

	i = 0;
	while (i < len)
	{
		if (!validation_of_array(stack[i]))
			return (false);
		i++;
	}
	return (true);
}

int main(int32_t argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (validation_of_list(argc - 1, &argv[1]))
			stack_a = init_the_stack(argc - 1, &argv[1]);
		else
			print_error();
		execute_operations(&stack_a, &stack_b);
		if (sort_status_check(stack_a))
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	else
		print_error();
	t_stack *iter;

	iter = stack_a;
	while (iter)
	{
		printf("%d ",iter->value);
		iter = iter->next;
		if (iter->head == true)
			break ;
	}
	system("leaks Push_swap");
	return (0);
}