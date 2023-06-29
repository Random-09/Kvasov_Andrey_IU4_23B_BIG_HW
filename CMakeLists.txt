cmake_minimum_required(VERSION 3.24)
project(big_hw C)

set(CMAKE_C_STANDARD 11)

add_executable(big_hw main.c src/authentication.c include/authentication.h src/init_db.c include/init_db.h src/menus.c include/menus.h src/log.c include/log.h src/book_funcs.c include/book_funcs.h src/students_funcs.c include/students_funcs.h src/book_sort.c include/book_sort.h src/save_and_free_db.c include/save_and_free_db.h src/data_input.c include/data_input.h sha-2/sha-256.c sha-2/sha-256.h)
