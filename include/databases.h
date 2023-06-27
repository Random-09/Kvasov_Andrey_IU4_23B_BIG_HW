#ifndef BIG_HW_DATABASES_H
#define BIG_HW_DATABASES_H

#include <stdbool.h>

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
