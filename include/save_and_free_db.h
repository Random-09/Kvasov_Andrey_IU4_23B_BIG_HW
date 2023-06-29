#ifndef BIG_HW_SAVE_AND_FREE_DB_H
#define BIG_HW_SAVE_AND_FREE_DB_H

#include <stdio.h>
#include <stdlib.h>
#include "init_db.h"

void save_books(Book_t *book_db_ptr, int number_of_books);

void save_students(Student_t *stud_db_ptr, int number_of_students);

void save_student_books(StudentBook_t *stud_book_db_ptr, int number_of_student_books);

void free_books_db(Book_t *book_db_ptr, int number_of_books);

void free_students_db(Student_t *stud_db_ptr, int number_of_students);

void free_users_db(User_t *user_db_ptr, int number_of_users);

void free_student_book_db(StudentBook_t *stud_book_db_ptr, int number_of_student_books);

#endif
