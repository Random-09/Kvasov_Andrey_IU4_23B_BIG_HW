#ifndef BIG_HW_INIT_DB_H
#define BIG_HW_INIT_DB_H

#include <stdbool.h>

#define STUDENTS_DB_FILE_PATH "../db/students.csv"
#define BOOKS_DB_FILE_PATH "../db/books.csv"
#define USERS_DB_FILE_PATH "../users.csv"
#define STUDENTS_BOOKS_DB_FILE_PATH "../student_books.csv"

// typedef struct AllDatabases {
//
// } AllDatabases_t;                                    <----- check if it works

typedef struct Students {
    char *record_book_num;
    char *surname;
    char *name;
    char *faculty;
    char *speciality;
} Students_t;

typedef struct Books {
    long ISBN;                  // <--- UNIQUE!
    char *author;
    char *title;
    int total_books;
    int available_books;
} Books_t;

typedef struct Users {
    char *login;
    char *hash;
    bool full_student_access;
    bool full_books_access;
} Users_t;

typedef struct StudentBooks {
    long ISBN;
    char *record_book_num;
    char *return_data;
} StudentBooks_t;

#endif
