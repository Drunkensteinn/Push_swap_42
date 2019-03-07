# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 17:41:44 by ablizniu          #+#    #+#              #
#    Updated: 2019/03/07 21:08:53 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

LIB_PATH := ../../libft/
OP_PATH := ../operations/
HDRS_PATH := ../../includes/
OBJ_PATH := ./obj/operations/
OBJ_PATH_ONE := ./obj/checker/
CHECKER_SRC := ../checker/

CC := clang
FLAGS := -Wall -Wextra -Werror -O3
IFLAGS := -I $(HDRS_PATH) -I $(LIB_PATH)
LFLAGS := -lft -L $(LIB_PATH)

LIB := $(LIB_PATH)libft.a
HDRS := errors op operations push_swap
FILES := algorithm_main \
			algorithm_start \
			algorithm_start_utils \
			algorithm_utils \
			conditions \
			init \
			main \
			output_instruction_optimization \
			output_instructions_utils \
			print \
			sort_utils \
			utils \
			validation
OP_FILES := op_push op_reverse_rotate op_rotate op_swap op_utils
FILES_ADDITIONAL := sort_check init stack_controller

SRCS += $(addsuffix .c, $(FILES))
SRCS += $(addprefix $(OP_PATH), $(addsuffix .c, $(OP_FILES)))
SRCS += $(addprefix $(CHECKER_SRC), $(addsuffix .c, $(FILES_ADDITIONAL)))
HDRS :=	$(addprefix $(HDRS_PATH), $(addsuffix .h, $(HDRS)))
OBJS := $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_PATH_ONE) $(OBJS)
		$(CC) $(FLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

$(LIB):
		$(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(OBJ_PATH_ONE):
		mkdir -p $(OBJ_PATH_ONE)

$(OBJ_PATH)%.o: %.c $(HDRS)
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)
		@$(MAKE) -sC $(LIB_PATH) clean

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ_PATH) $(OBJ_PATH_ONE) $(OBJS) obj/
		@$(MAKE) -sC $(LIB_PATH) fclean

re:
		@$(MAKE) fclean
		@$(MAKE) all