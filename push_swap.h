/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:47:41 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/04 22:58:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include "operations.h"

#define MIN_ELEMS 3
#define	MARKED INT64_MAX
#define UNMARKED INT64_MIN

#define	ASCENDING(x,y)		(x <= y)

typedef struct			s_stack
{
		t_bool			head;
		int32_t			value;
		int64_t			mediana;
		struct s_stack	*prev;
		struct s_stack	*next;
}						t_stack;

typedef	struct			s_command
{
	char				*command;
	struct 	s_command	*prev;
	struct 	s_command	*next;
}						t_command;

void					optimize_commands(t_command *lst);

size_t					block_len(t_stack *stack);

void					solution_a(t_stack **a, t_stack **b, t_command **list);

t_stack					*search_elem(t_stack *stack, size_t len);

size_t					split_a(t_stack **a, t_stack **b, size_t *len_a_top, size_t *len_a_bot);

size_t					split_b(t_stack **a, t_stack **b, size_t *len_b_bot, size_t *elems);

int32_t					find_mediana_for_stack(t_stack *stack, size_t stack_len);

void					sort(t_stack **stack_a, t_command **list);

int32_t					pushing_by_mediana(t_stack **a, t_stack **b, int32_t mediana, t_command **list);

int32_t					*init_array(t_stack *stack, size_t len);

int32_t					*init_map(size_t len, size_t *len_map);

void					print_op(const char *op);

t_bool					validation_of_list(int32_t len, char **stack);

t_stack					*init_elem(void);

t_stack					*init_the_stack(int32_t num, char **value);

void					print_error(void);

void					create_new_elem(t_stack **lst, t_stack *prev, int32_t elem);


void					check_created_elem(t_stack **stack, t_stack *prev,
						char **data, size_t index);

void push_and_sort(t_stack **a, t_stack **b, size_t *len, t_command **list);


size_t					stack_length(t_stack *stack);

void					print_array(int32_t *array, size_t	len);

void					print_stack(t_stack *stack, size_t size);

void					quick_sort(int32_t *array, int32_t len_l, int32_t len_r);

void 					swap(int *a, int *b);

size_t					dilimeter(size_t len);

void					pre_sorting(t_stack **a, t_stack **b, int32_t *map,
									t_command **command);

int32_t					search_mediana(int32_t *array, size_t len);

void					algorithm_init(t_stack *a, t_stack *b);

t_bool					condition_for_push(t_stack *stack, int32_t value);

t_bool					condition_for_sort(t_stack *stack);

#endif
