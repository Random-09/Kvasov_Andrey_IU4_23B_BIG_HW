#ifndef BIG_HW_BOOK_SORT_H
#define BIG_HW_BOOK_SORT_H

#include "init_db.h"

void merge(Book_t *array, int left, int middle, int right);

void books_merge_sort(Book_t *array, int left, int right);

#endif