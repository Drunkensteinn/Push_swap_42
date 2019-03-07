# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 17:41:44 by ablizniu          #+#    #+#              #
#    Updated: 2019/03/07 20:30:23 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := checker

LIB_PATH := ../../libft/
OP_PATH := ../operations/
HDRS_PATH := ../../includes/
OBJ_PATH := ./obj/operations/
OBJ_PATH_TWO := ./obj/push_swap/
PUSH_SWAP_SRC := ../push_swap/

CC := clang
FLAGS := -Wall -Wextra -Werror -O3
IFLAGS := -I $(HDRS_PATH) -I $(LIB_PATH)
LFLAGS := -lft -L $(LIB_PATH)

LIB := $(LIB_PATH)libft.a
HDRS := errors op operations push_swap
FILES := init main operations_controller sort_check stack_controller
OP_FILES := op_push op_reverse_rotate op_rotate op_swap op_utils
FILES_ADDITIONAL := print validation init utils

SRCS += $(addsuffix .c, $(FILES))
SRCS += $(addprefix $(OP_PATH), $(addsuffix .c, $(OP_FILES)))
SRCS += $(addprefix $(PUSH_SWAP_SRC), $(addsuffix .c, $(FILES_ADDITIONAL)))
HDRS :=	$(addprefix $(HDRS_PATH), $(addsuffix .h, $(HDRS)))
OBJS := $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_PATH_TWO) $(OBJS)
		$(CC) $(FLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

$(LIB):
		$(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(OBJ_PATH_TWO):
		mkdir -p $(OBJ_PATH_TWO)

$(OBJ_PATH)%.o: %.c $(HDRS)
		$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)
		@$(MAKE) -sC $(LIB_PATH) clean

fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ_PATH) $(OBJ_PATH_TWO) $(OBJS) obj/
		@$(MAKE) -sC $(LIB_PATH) fclean

re:
		@$(MAKE) fclean
		@$(MAKE) all