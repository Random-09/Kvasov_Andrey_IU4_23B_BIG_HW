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

int book_index_by_isbn(Book_t *book_db_ptr, int number_of_books, long long ISBN);

void add_book(Book_t *book_db_ptr, int *number_of_books);

void delete_book(Book_t *book_db_ptr, int *number_of_books,
                 StudentBook_t *stud_book_db_ptr, int number_of_student_books);

void book_info(Book_t *book_db_ptr, int number_of_books,
               StudentBook_t *stud_book_db_ptr, int number_of_stud_books,
               Student_t *stud_db_ptr, int number_of_students);

void all_books_info(Book_t *book_db_ptr, int number_of_books);

void print_book_info(Book_t *book);

void edit_book_info(Book_t *book_db_ptr, int number_of_books, int number_of_students);

void change_total_number_of_books(Book_t *book_db_ptr, int number_of_books);

void give_a_book(Book_t *book_db_ptr, int number_of_books,
                 StudentBook_t *stud_book_db_ptr, int *number_of_student_books);

void receive_a_book(Book_t *book_db_ptr, int number_of_books,
                    StudentBook_t *stud_book_db_ptr, int *number_of_student_books);

#endif
