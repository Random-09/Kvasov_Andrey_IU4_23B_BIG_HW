#include "../include/menus.h"

void show_admin_menu(Student_t *stud_db_ptr, int *number_of_students,
                     Book_t *book_db_ptr, int *number_of_books,
                     StudentBook_t *stud_book_db_ptr, int *number_of_student_books,
                     char *login) {
    bool running = true;
    while (running) {
        add_log(login, "Entered admin menu");
        puts("1. Enter book action menu\n2. Enter student action menu\n");
        char input;
        int choice;
        int entry_count = 0;
        do {
            if (entry_count > 0)
                puts("Please enter a number as a choice");
            scanf("%c", &input);
            entry_count++;
        } while (!isdigit(input));
        switch (choice) {
            case SHOW_BOOKS_MENU:
                show_books_menu(stud_db_ptr, *number_of_students,
                                book_db_ptr, number_of_books,
                                stud_book_db_ptr, number_of_student_books,
                                login, true);
                break;
            case SHOW_STUDENTS_MENU:
                show_students_menu(stud_db_ptr, number_of_students,
                                   book_db_ptr, *number_of_books,
                                   stud_book_db_ptr, *number_of_student_books,
                                   login, true);
                break;
            case ADMIN_EXIT:
                add_log(login, "Exited admin menu");
                running = false;
                break;
            default:
                puts("Please enter a specified number as a choice");
                break;
        }
    }
}

void show_books_menu(Student_t *stud_db_ptr, int number_of_students,
                     Book_t *book_db_ptr, int *number_of_books,
                     StudentBook_t *stud_book_db_ptr, int *number_of_student_books,
                     char *login, bool link_to_admin_menu) {
    bool running = true;
    while (running) {
        add_log(login, "Entered books menu");
        puts("1. Add a new book\n2. Delete a book\n3. See information about a book\n4. See information about"
             " all books\n5. Edit book info\n6. Change amount of available books\n7. Give a book to the student\n"
             "8. Receive a book from a student\n");
        if (link_to_admin_menu)
            puts("0. Exit to admin menu\n");
        char input;
        int choice;
        int entry_count = 0;
        do {
            if (entry_count > 0)
                puts("Please enter a number as a choice");
            scanf("%c", &input);
            entry_count++;
        } while (!isdigit(input));
        choice = atoi(&input);
        switch (choice) {
            case ADD_A_BOOK:
                add_book(book_db_ptr, number_of_books);
                add_log(login, "Add a book");
                break;
            case DELETE_A_BOOK:
                delete_book(book_db_ptr, number_of_books,
                            stud_book_db_ptr, *number_of_student_books);
                add_log(login, "Delete a book");
                break;
            case INFO_ABOUT_A_BOOK:
                book_info(book_db_ptr, *number_of_books,
                          stud_book_db_ptr, *number_of_student_books,
                          stud_db_ptr, number_of_students);
                add_log(login, "Info about a book");
                break;
            case ALL_BOOK_INFO:
                all_books_info(book_db_ptr, *number_of_books);
                add_log(login, "All book info");
                break;
            case EDIT_BOOK_INFO:
                edit_book_info(book_db_ptr, *number_of_books, number_of_students);
                add_log(login, "Edit book info");
                break;
            case CHANGE_BOOK_AMOUNT:
                change_total_number_of_books(book_db_ptr, *number_of_books);
                add_log(login, "Change book amount");
                break;
            case GIVE_A_BOOK:
                give_a_book(book_db_ptr, *number_of_books,
                            stud_book_db_ptr, number_of_student_books);
                add_log(login, "Give a book");
                break;
            case RECEIVE_A_BOOK:
                receive_a_book(book_db_ptr, *number_of_books,
                               stud_book_db_ptr, number_of_student_books);
                add_log(login, "Receive a book");
                break;
            case BOOKS_EXIT:
                add_log(login, "Exited books menu");
                running = false;
                break;
            default:
                puts("Please enter a specified number as a choice");
                break;
        }
    }
}

void show_students_menu(Student_t *stud_db_ptr, int *number_of_students,
                        Book_t *book_db_ptr, int number_of_books,
                        StudentBook_t *stud_book_db_ptr, int number_of_student_books,
                        char *login, bool link_to_admin_menu) {
    bool running = true;
    while (running) {
        add_log(login, "Entered students menu");
        puts("1. Add a student\n2. Delete a student\n3. Edit information about student\n4. Show information "
             "about student\n5. Search a student by surname\n");
        if (link_to_admin_menu)
            puts("0. Exit to admin menu\n");
        char input;
        int choice;
        int entry_count = 0;
        do {
            if (entry_count > 0)
                puts("Please enter a number as a choice");
            scanf("%c", &input);
            entry_count++;
        } while (!isdigit(input));
        choice = atoi(&input);
        switch (choice) {
            case ADD_A_STUDENT:
                add_student(stud_db_ptr, number_of_students);
                add_log(login, "Add a student");
                break;
            case DELETE_A_STUDENT:
                delete_student(stud_db_ptr, number_of_students,
                               stud_book_db_ptr, number_of_student_books);
                add_log(login, "Delete a student");
                break;
            case EDIT_STUDENT_INFO:
                edit_student_info(stud_db_ptr, *number_of_students);
                add_log(login, "Edit student info");
                break;
            case STUDENT_INFO_BY_RECORD_BOOK:
                show_student_info_by_record_book(stud_db_ptr, *number_of_students,
                                                 stud_book_db_ptr, number_of_student_books,
                                                 book_db_ptr, number_of_books);
                add_log(login, "Student info by record book");
                break;
            case STUDENT_INFO_BY_SURNAME:
                show_student_info_by_surname(stud_db_ptr, *number_of_students);
                add_log(login, "Student info by surname");
                break;
            case STUDENT_EXIT:
                add_log(login, "Exited student menu");
                running = false;
                break;
            default:
                puts("Please enter a specified number as a choice");
                break;
        }
    }
}
