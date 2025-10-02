cmake_minimum_required(VERSION 4.0)
project(Year1Lab C)

set(CMAKE_C_STANDARD 99)

add_executable(Year1Lab main.c
        local_var.c
        global_var.c
        local_global_var.c
        external_var.h
        static_var.c)
