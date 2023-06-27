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
    EXIT = 0,
    ADD_A_BOOK,
    DELETE_A_BOOK,
    INFO_ABOUT_A_BOOK,
    ALL_BOOK_INFO,
    EDIT_BOOK_INFO,
    CHANGE_BOOK_AMOUNT,
    GIVE_A_BOOK,
    RECEIVE_A_BOOK
};

void show_books_menu(bool link_to_admin_menu);

void show_students_menu();

#endif
