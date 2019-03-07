cmake_minimum_required(VERSION 3.12)
project(Push_swap C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC} libft/ft_arrdup.c includes/errors.h)

#add_executable(Checker checker/main.c push_swap.h checker/init.c checker/stack_controller.c checker/operations_controller.c checker/sort_check.c operations.h operations/op_utils.c)


include_directories(operations)

add_executable(Push_swap push_swap/main.c push_swap/init.c push_swap/algorithm_start_utils.c push_swap/print.c
        push_swap/utils.c
        push_swap/algorithm_start.c
        checker/stack_controller.c
        checker/init.c
        operations/op_push.c
        operations/op_reverse_rotate.c
        operations/op_rotate.c
        operations/op_swap.c
        operations/op_utils.c push_swap/conditions.c push_swap/sort_utils.c checker/operations_controller.c
        checker/sort_check.c push_swap/algorithm_main.c push_swap/algorithm_utils.c push_swap/output_instructions_utils.c push_swap/output_instruction_optimization.c push_swap/validation.c)
target_link_libraries(Push_swap ft)