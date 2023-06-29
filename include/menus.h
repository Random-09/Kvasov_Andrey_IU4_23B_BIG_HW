#ifndef BIG_HW_MENUS_H
#define BIG_HW_MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "book_funcs.h"
#include "students_funcs.h"
#include "init_db.h"
#include "log.h"

enum admin_choice {
    ADMIN_EXIT = 0,
    SHOW_BOOKS_MENU,
    SHOW_STUDENTS_MENU
};

enum books_choice {
    BOOKS_EXIT = 0,
    ADD_A_BOOK,
    DELETE_A_BOOK,
    INFO_ABOUT_A_BOOK,
    ALL_BOOK_INFO,
    EDIT_BOOK_INFO,
    CHANGE_BOOK_AMOUNT,
    GIVE_A_BOOK,
    RECEIVE_A_BOOK
};

enum student_choice {
    STUDENT_EXIT = 0,
    ADD_A_STUDENT,
    DELETE_A_STUDENT,
    EDIT_STUDENT_INFO,
    STUDENT_INFO_BY_RECORD_BOOK,
    STUDENT_INFO_BY_SURNAME
};

void show_admin_menu(Student_t *stud_db_ptr, int *number_of_students,
                     Book_t *book_db_ptr, int *number_of_books,
                     StudentBook_t *stud_book_db_ptr, int *number_of_student_books,
                     char *login);

void show_books_menu(Student_t *stud_db_ptr, int number_of_students,
                     Book_t *book_db_ptr, int *number_of_books,
                     StudentBook_t *stud_book_db_ptr, int *number_of_student_books,
                     char *login, bool link_to_admin_menu);

void show_students_menu(Student_t *stud_db_ptr, int *number_of_students,
                        Book_t *book_db_ptr, int number_of_books,
                        StudentBook_t *stud_book_db_ptr, int number_of_student_books,
                        char *login, bool link_to_admin_menu);

#endif
