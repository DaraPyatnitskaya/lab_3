cmake_minimum_required(VERSION 3.10)
project(MemoryLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(manual_leak manual_leak.cpp)
add_executable(unique_ptr_example unique_ptr_example.cpp)
add_executable(shared_ptr_example shared_ptr_example.cpp)
add_executable(weak_ptr_example weak_ptr_example.cpp)
