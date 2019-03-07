# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 17:00:34 by ablizniu          #+#    #+#              #
#    Updated: 2019/03/07 21:56:02 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP := push_swap
CHECKER := checker

P_PATH := src/push_swap/
C_PATH := src/checker/

RED := \033[0;31m
GREEN := \033[0;32m
RESET := \033[0m

make:
	@$(MAKE) -C $(P_PATH)
	@$(MAKE) -C $(C_PATH)
	@ln -fs $(P_PATH)$(PUSH_SWAP) $(PUSH_SWAP)
	@ln -fs $(C_PATH)$(CHECKER) $(CHECKER)
	@chmod 744 $(PUSH_SWAP) $(CHECKER)
	@echo "$(GREEN) $(PUSH_SWAP) and $(CHECKER) links was created$(RESET)"
clean:
	@$(MAKE) clean -C $(P_PATH)
	@$(MAKE) clean -C $(C_PATH)
fclean:
	@$(MAKE) fclean -C $(P_PATH)
	@$(MAKE) fclean -C $(C_PATH)
	@rm -f $(PUSH_SWAP) $(CHECKER)
	@echo "$(RED)Files was deleted$(RESET)"
re:
	@$(MAKE) re -C $(P_PATH)
	@$(MAKE) re -C $(C_PATH)
	@ln -fs $(P_PATH)$(PUSH_SWAP) $(PUSH_SWAP)
	@ln -fs $(C_PATH)$(CHECKER) $(CHECKER)
	@chmod 744 $(PUSH_SWAP) $(CHECKER)
	@echo "$(GREEN) $(PUSH_SWAP) and $(CHECKER) links was created$(RESET)"