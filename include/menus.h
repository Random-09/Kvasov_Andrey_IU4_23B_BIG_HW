#ifndef BIG_HW_MENUS_H
#define BIG_HW_MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

enum admin_choice {
    SHOW_BOOKS_MENU = 1,
    SHOW_STUDENTS_MENU
};

enum books_choice {

};

void show_books_menu();

void show_students_menu();

#endif
