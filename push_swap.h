/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:47:41 by ablizniu          #+#    #+#             */
/*   Updated: 2019/02/04 21:26:28 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include "operations.h"

#define RANDOM_INDEX(x) (x * 0.2985)


#define  ASCENDING(x,y)		(x <= y)

typedef struct			s_stack
{
		t_bool			head;
		int32_t			value;
		struct s_stack	*prev;
		struct s_stack	*next;
}						t_stack;


int32_t					*init_array(int32_t len, char **data);

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

int32_t					rec_search(int32_t *start, int32_t *end,size_t len, int32_t sup_elem);

int32_t					search_mediana(int32_t *array, size_t len);

int						*ft_arrdup(const int *dst, size_t len);

void					algorhythm(int32_t *array, size_t len);


#endif
