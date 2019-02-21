/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:47:41 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/18 15:11:46 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include "operations.h"

#define MIN_STACK_LEN 3
#define	TOP 2
#define BOT 1

#define	ASCENDING(x,y)		(x <= y)

typedef struct			s_stack
{
		t_bool			head;
		int32_t			value;
		struct s_stack	*prev;
		struct s_stack	*next;
}						t_stack;

int32_t					find_mediana_for_block(int32_t *block, int32_t stack_len);

void					sort(t_stack **stack_a, t_bool is_asscending);

void					sort_min_stack_len_and_push(t_stack **a, t_stack **b, int32_t *len);

void					pushing_by_mediana(t_stack **a, t_stack **b, int32_t mediana,
						int32_t *elem);
void	push_top_and_bot(t_stack **a, t_stack **b, size_t *len_bot, size_t *len_top);

int32_t					*init_array(int32_t len, t_stack *stack);

int32_t *init_map(size_t len, size_t *len_map);

void					print_op(const char *op);

t_bool					validation_of_list(int32_t len, char **stack);

t_stack					*init_elem(void);

t_stack					*init_the_stack(int32_t num, char **value);

void					print_error(void);

void					create_new_elem(t_stack **lst, t_stack *prev, int32_t elem);

t_bool					sort_status_check(t_stack *stack);

void					check_created_elem(t_stack **stack, t_stack *prev,
						char **data, size_t index);

void					execute_operations(t_stack **stack_a, t_stack **stack_b);

size_t					stack_length(t_stack *stack);

void					print_array(int32_t *array, size_t	len);

void					print_stack(t_stack *stack, size_t size);

void					quick_sort(int32_t *array, int32_t len_l, int32_t len_r);

void 					swap(int *a, int *b);

size_t					dilimeter(size_t len);

void					pre_sorting(t_stack **a, t_stack **b, int32_t *map, int32_t len);

int32_t					search_mediana(int32_t *array, size_t len);

void					algorithm_init(t_stack *a, t_stack *b, int32_t argc);

t_bool					condition_for_push(t_stack *stack, int32_t value);

t_bool					condition_for_sort(t_stack *stack);

#endif
