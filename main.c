#include <stdlib.h>
#include "include/init_db.h"
#include "include/authentication.h"
#include "include/menus.h"
#include "include/save_and_free_db.h"
#include "include/log.h"

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
    char *login = user_db_ptr[index].login;
    add_log(login, "Authentication successful");

    if (user_db_ptr[index].full_books_access && user_db_ptr[index].full_student_access)
        show_admin_menu(login);
    if (user_db_ptr[index].full_books_access && !user_db_ptr[index].full_student_access)
        show_books_menu(login, false);
    if (!user_db_ptr[index].full_books_access && user_db_ptr[index].full_student_access)
        show_students_menu(login, false);

    save_books(book_db_ptr, number_of_books);
    save_students(stud_db_ptr, number_of_students);
    save_student_books(stud_book_db_ptr, number_of_student_books);

    free_books_db(book_db_ptr, number_of_books);
    free_students_db(stud_db_ptr, number_of_students);
    free_users_db(user_db_ptr, number_of_users);
    free_student_book_db(stud_book_db_ptr, number_of_student_books);

    add_log(login, "Save and free db successfully");

    return EXIT_SUCCESS;
}
