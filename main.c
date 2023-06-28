#include <stdio.h>
#include <stdlib.h>
#include "include/init_db.h"
#include "include/authentication.h"
#include "include/menus.h"

int main() {
    int number_of_students = 0;
    int number_of_books = 0;
    int number_of_users = 0;
    int number_of_student_books = 0;
    Student_t *stud_db_ptr = init_students_db(&number_of_students);
    Book_t *book_db_ptr = init_books_db(&number_of_books);
    User_t *user_db_ptr = init_users_db(&number_of_users);
    StudentBook_t *stud_book_db_ptr = init_student_book_db(&number_of_student_books);
    int index;
    do {
        index = authentication(user_db_ptr, number_of_users);
    } while (index == -1);
    if (user_db_ptr[index].full_books_access && user_db_ptr[index].full_student_access)
        show_admin_menu();
    if (user_db_ptr[index].full_books_access && !user_db_ptr[index].full_student_access)
        show_books_menu(false);
    if (!user_db_ptr[index].full_books_access && user_db_ptr[index].full_student_access)
        show_students_menu(false);

    // ALL DBs?

    return EXIT_SUCCESS;
}
