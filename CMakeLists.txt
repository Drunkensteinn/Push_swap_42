cmake_minimum_required(VERSION 3.12)
project(src/push_swap C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(libft LBFT_SRC)
add_library(ft STATIC ${LBFT_SRC} libft/ft_arrdup.c includes/errors.h)

#add_executable(Checker checker/main.c push_swap.h checker/init.c checker/stack_controller.c checker/operations_controller.c checker/sort_check.c operations.h operations/op_utils.c)


include_directories(src/operations)
include_directories(includes)
include_directories(libft)

add_executable(src/push_swap src/push_swap/main.c src/push_swap/init.c src/push_swap/algorithm_start_utils.c src/push_swap/print.c
                src/push_swap/utils.c
                src/push_swap/algorithm_start.c
                src/checker/stack_controller.c
                src/checker/init.c
                src/operations/op_push.c
                src/operations/op_reverse_rotate.c
                src/operations/op_rotate.c
                src/operations/op_swap.c
                src/operations/op_utils.c src/push_swap/conditions.c src/push_swap/sort_utils.c src/checker/operations_controller.c
                src/checker/sort_check.c src/push_swap/algorithm_main.c src/push_swap/algorithm_utils.c src/push_swap/output_instructions_utils.c src/push_swap/output_instruction_optimization.c src/push_swap/validation.c)
target_link_libraries(src/push_swap ft)