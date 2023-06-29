#include "../include/menus.h"
#include "../include/log.h"

void show_admin_menu(char *login) {                                                         // <--- Add while loop!
    add_log(login, "Entered admin menu");
    puts("1. Enter book action menu\n2. Enter student action menu\n");
    int choice;
    int entry_count = 0;
    do {
        if (entry_count > 0)
            puts("Please enter 1 or 2 as a choice");
        scanf("%d", &choice);
        entry_count++;
    } while (choice != 1 && choice != 2);
    switch (choice) {
        case SHOW_BOOKS_MENU:
            show_books_menu(login, true);
            break;
        case SHOW_STUDENTS_MENU:
            show_students_menu(login, true);
            break;
        default:
            break;                                  // <----
    }
}

void show_books_menu(char *login, bool link_to_admin_menu) {                                 // <--- Add while loop!
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
            puts("Please enter a specified number as a choice");
        scanf("%c", &input);
        entry_count++;
    } while (!isdigit(input) && atoi(&input) == 9);
    choice = atoi(&input);
    switch (choice) {
        case ADD_A_BOOK:
            add_log(login, "Add a book");
            break;
        case DELETE_A_BOOK:
            add_log(login, "Delete a book");
            break;
        case INFO_ABOUT_A_BOOK:
            add_log(login, "Info about a book");
            break;
        case ALL_BOOK_INFO:
            add_log(login, "All book info");
            break;
        case EDIT_BOOK_INFO:
            add_log(login, "Edit book info");
            break;
        case CHANGE_BOOK_AMOUNT:
            add_log(login, "Change book amount");
            break;
        case GIVE_A_BOOK:
            add_log(login, "Give a book");
            break;
        case RECEIVE_A_BOOK:
            add_log(login, "Receive a book");
            break;
        case BOOKS_EXIT:
            add_log(login, "Exited books menu");
            break;
        default:
            break;                                      // <---
    }
}

void show_students_menu(char *login, bool link_to_admin_menu) {                          // <--- Add while loop
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
            puts("Please enter a specified number as a choice");
        scanf("%c", &input);
        entry_count++;
    } while (!isdigit(input) && atoi(&input) == 9);
    choice = atoi(&input);
    switch (choice) {
        case ADD_A_STUDENT:
            add_log(login, "Add a student");
            break;
        case DELETE_A_STUDENT:
            add_log(login, "Delete a student");
            break;
        case EDIT_STUDENT_INFO:
            add_log(login, "Edit student info");
            break;
        case STUDENT_INFO_BY_RECORD_BOOK:
            add_log(login, "Student info by record book");
            break;
        case STUDENT_INFO_BY_SURNAME:
            add_log(login, "Student info by surname");
            break;
        case STUDENT_EXIT:
            add_log(login, "Exited student menu");
            break;
        default:
            break;                                  // <----
    }
}
