#ifndef BIG_HW_INIT_DB_H
#define BIG_HW_INIT_DB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LEN 128
#define STUDENTS_DB_FILE_PATH "../db/students.csv"
#define BOOKS_DB_FILE_PATH "../db/books.csv"
#define USERS_DB_FILE_PATH "../users.csv"
#define STUDENTS_BOOKS_DB_FILE_PATH "../student_books.csv"

// typedef struct AllDatabases {
//
// } AllDatabases_t;                                    <----- check if it works

typedef struct Student {
    char *record_book_num;
    char *surname;
    char *name;
    char *faculty;
    char *speciality;
} Student_t;

typedef struct Book {
    long ISBN;                  // <--- UNIQUE!
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
    long ISBN;
    char *record_book_num;
    char *return_date;
} StudentBook_t;

#endif
