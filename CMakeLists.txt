cmake_minimum_required(VERSION 4.0)
project(Year1Lab C)

set(CMAKE_C_STANDARD 99)

add_executable(new_target lab0/global_var.c
        lab0/local_global_var.c
        lab0/local_var.c
        lab0/main.c
        lab0/static_var.c)
