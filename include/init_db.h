#ifndef BIG_HW_INIT_DB_H
#define BIG_HW_INIT_DB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "log.h"

#define STUDENTS_DB_CAPACITY 50
#define BOOKS_DB_CAPACITY 100
#define USERS_DB_CAPACITY 50
#define STUDENT_BOOKS_DB_CAPACITY 200

#define MAX_LINE_LEN 128
#define STUDENTS_DB_FILE_PATH "../db/students.csv"
#define BOOKS_DB_FILE_PATH "../db/books.csv"
#define USERS_DB_FILE_PATH "../db/users.csv"
#define STUDENTS_BOOKS_DB_FILE_PATH "../db/student_books.csv"

typedef struct Student {
    char *record_book_num;
    char *surname;
    char *name;
    char *faculty;
    char *speciality;
} Student_t;

typedef struct Book {
    long long ISBN;
    char *author;
    char *title;
    int total_books;
    int available_books;
} Book_t;

typedef struct User {
    char *login;
    char *hash;
    bool full_student_access;
    bool full_books_access;
} User_t;

typedef struct StudentBook {
    long long ISBN;
    char *record_book_num;
    char *return_date;
} StudentBook_t;

Student_t *init_students_db(int *number_of_students);

Book_t *init_books_db (int *number_of_books);

User_t *init_users_db(int *number_of_users);

StudentBook_t *init_student_book_db(int *number_of_student_books);

#endif
