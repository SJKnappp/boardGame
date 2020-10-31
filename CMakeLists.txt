project(board)
cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(checkers)
add_subdirectory(snake)
add_subdirectory(tic)
add_subdirectory(tui)

add_executable(Main
        main.cpp)

target_link_libraries(Main
       tui checkers snake tic)

target_link_libraries(Main -lncurses)