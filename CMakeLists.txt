cmake_minimum_required(VERSION 3.12)
project(Push_swap C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC} libft/ft_arrdup.c)

#add_executable(Checker checker/main.c push_swap.h checker/init.c checker/stack_controller.c checker/operations_controller.c checker/sort_check.c operations.h operations/op_utils.c)


include_directories(operations)

add_executable(Push_swap push_swap/main.c push_swap/init.c push_swap/preparation.c push_swap/print_op.c
        push_swap/utils.c
        push_swap/algorithm.c
        checker/stack_controller.c
        checker/init.c
        operations/op_push.c
        operations/op_reverse_rotate.c
        operations/op_rotate.c
        operations/op_swap.c
        operations/op_utils.c push_swap/conditions.c push_swap/sort_utils.c checker/operations_controller.c)
target_link_libraries(Push_swap ft)