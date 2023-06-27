cmake_minimum_required(VERSION 3.24)
project(big_hw C)

set(CMAKE_C_STANDARD 11)

add_executable(big_hw main.c src/authentication.c include/authentication.h src/databases.c include/databases.h)
