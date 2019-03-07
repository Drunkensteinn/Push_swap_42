# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 17:00:34 by ablizniu          #+#    #+#              #
#    Updated: 2019/03/07 21:33:45 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker

P_PATH = push_swap/
C_PATH = checker/

make:
	@$(MAKE) -C $(P_PATH)
	@$(MAKE) -C $(C_PATH)
	@ln -fs $(P_PATH)$(PUSH_SWAP) $(PUSH_SWAP)
	@ln -fs $(C_PATH)$(CHECKER) $(CHECKER)
	@chmod 744 $(PUSH_SWAP) $(CHECKER)
re:
	@$(MAKE) re -C $(P_PATH)
	@$(MAKE) re -C $(C_PATH)
	@ln -s $(P_PATH)$(PUSH_SWAP) $(PUSH_SWAP)
	@ln -s $(C_PATH)$(CHECKER) $(CHECKER)
	@chmod 744 $(PUSH_SWAP) $(CHECKER)
clean:
	@$(MAKE) clean -C $(P_PATH)
	@$(MAKE) clean -C $(C_PATH)
fclean:
	@$(MAKE) fclean -C $(P_PATH)
	@$(MAKE) fclean -C $(C_PATH)
	rm -f $(PUSH_SWAP) $(CHECKER)