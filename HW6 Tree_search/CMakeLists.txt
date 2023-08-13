cmake_minimum_required(VERSION 3.0.0)
project(maze VERSION 0.1.0)
# --- Your code here
add_library(maze_impl maze_impl.cpp)
add_library(maze_impl_student maze_impl_student.cpp)

add_executable(maze maze_main.cpp)
target_link_libraries(maze maze_impl maze_impl_student)
# ---
