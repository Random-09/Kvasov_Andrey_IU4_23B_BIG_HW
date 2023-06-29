#ifndef BIG_HW_BOOK_FUNCS_H
#define BIG_HW_BOOK_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "init_db.h"
#include "data_input.h"
#include "book_sort.h"

enum book_choice {
    EXIT = 0,
    AUTHOR,
    TITLE,
    TOTAL_BOOK_NUM
};

void print_book_info(Book_t *book);

#endif
