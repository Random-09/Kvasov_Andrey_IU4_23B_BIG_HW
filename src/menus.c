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
            show_books_menu();
            break;
        case SHOW_STUDENTS_MENU:
            show_students_menu();
            break;
        default:
            break;
    }
}

void show_books_menu() {

}

void show_student_menu() {

}
