#ifndef BIG_HW_BOOK_FUNCS_H
#define BIG_HW_BOOK_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "init_db.h"
#include "data_input.h"
#include "book_sort.h"
#include "log.h"
#include "students_funcs.h"

enum book_choice {
    BOOK_EDIT_EXIT = 0,
    AUTHOR,
    TITLE,
    TOTAL_BOOK_NUM
};

void change_total_number_of_books(Book_t *book_db_ptr, int number_of_books);

void print_book_info(Book_t *book);

#endif
