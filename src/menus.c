#include "../include/menus.h"

void show_admin_menu() {
    puts("1. Enter book action menu\n2. Enter student action menu");
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
            show_books_menu(true);
            break;
        case SHOW_STUDENTS_MENU:
            show_students_menu();
            break;
        default:
            break;
    }
}

void show_books_menu(bool link_to_admin_menu) {
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
            break;
        case DELETE_A_BOOK:
            break;
        case INFO_ABOUT_A_BOOK:
            break;
        case
    }
}

void show_student_menu() {

}
