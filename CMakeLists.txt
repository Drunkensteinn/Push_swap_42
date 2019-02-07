cmake_minimum_required(VERSION 3.12)
project(Push_swap C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC})

#add_executable(Checker checker/main.c push_swap.h checker/init.c checker/stack_controller.c checker/operations_controller.c checker/sort_check.c operations.h operations/op_utils.c)




add_executable(Push_swap push_swap/main.c push_swap/init.c push_swap/algorhythm.c push_swap/print_op.c push_swap/utils.c)
target_link_libraries(Push_swap ft)