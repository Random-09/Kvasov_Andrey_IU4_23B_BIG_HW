#include <stdio.h>
#include <stdlib.h>
#include "include/init_db.h"

int main() {
    int number_of_students = 0;
    int number_of_books = 0;
    int number_of_users = 0;
    int number_of_student_books = 0;
    Student_t *stud_db_ptr = init_students_db(&number_of_students);
    Book_t *book_db_ptr = init_books_db(&number_of_books);
    User_t *user_db_ptr = init_users_db(&number_of_users);
    Student_t *stud_book_db_ptr = init_students_db(&number_of_student_books);

    return EXIT_SUCCESS;
}
