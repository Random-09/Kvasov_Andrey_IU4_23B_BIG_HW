#include "../include/book_funcs.h"

int book_index_by_isbn(Book_t *book_db_ptr, int number_of_books, long ISBN) {
    for (int i = 0; i < number_of_books; i++) {
        if (book_db_ptr[i].ISBN == ISBN)
            return i;
    }
    return -1;
}

void add_book(Book_t *book_db_ptr, int *number_of_books) {
    if (*number_of_books == BOOKS_DB_CAPACITY) {
        puts("Books db capacity reached");
        return;
    }

    puts("Enter ISBN of a book");
    long ISBN = long_input();

    if (book_index_by_isbn(book_db_ptr, *number_of_books, ISBN) != -1) {
        puts("Student with this record book number is already in the database");
        return;
    }

    puts("Enter author of a book");
    char *author = (char *) malloc(AUTHOR_SIZE * sizeof(char));
    str_input(author, AUTHOR_SIZE);

    puts("Enter title of a book");
    char *title = (char *) malloc(TITLE_SIZE * sizeof(char));
    str_input(title, TITLE_SIZE);

    puts("Enter total number of books");
    int total_books = int_input();

    puts("Enter number of available books");
    int available_books = int_input();

    Book_t book = {ISBN, author, title, total_books, available_books};
    book_db_ptr[*number_of_books] = book;
    (*number_of_books)++;
    puts("Book added successfully!");
}

void delete_book(Book_t *book_db_ptr, int *number_of_books,
                 StudentBook_t *stud_book_db_ptr, int number_of_student_books) {
    if (*number_of_books == 0) {
        puts("Database is empty, can't delete any book");
        return;
    }

    puts("Enter ISBN of a book you want to delete");
    long ISBN = long_input();

    for (int i = 0; i < number_of_student_books; i++) {
        if (stud_book_db_ptr[i].ISBN == ISBN) {
            puts("Can't delete this book, because not all students have returned it");
            return;
        }
    }

    int index = book_index_by_isbn(book_db_ptr, *number_of_books, ISBN);
    if (index == -1) {
        puts("This books is not in the database");
        return;
    }
    for (int i = index; i < *number_of_books - 1; i++) {
        book_db_ptr[i] = book_db_ptr[i + 1];
    }
    free(book_db_ptr[*number_of_books].author);
    free(book_db_ptr[*number_of_books].title);
    (*number_of_books)--;
}

void book_info(Book_t *book_db_ptr, int number_of_books,
               StudentBook_t *stud_book_db_ptr, int number_of_stud_books,
               Student_t *stud_db_ptr, int number_of_students) {
    puts("Enter ISBN of a book you want to see");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_books, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }
    print_book_info(&book_db_ptr[index]);

    puts("Students that have this book:");
    for (int i = 0; i < number_of_stud_books; i++) {
        if (stud_book_db_ptr[i].ISBN == ISBN) {
            for (int j = 0; j < number_of_students; j++) {
                if (!strcmp(stud_book_db_ptr[i].record_book_num, stud_db_ptr[j].record_book_num))
                    printf("%s %s\n", stud_db_ptr[j].surname, stud_db_ptr[j].name);
            }
        }
    }
}

void all_books_info(Book_t *book_db_ptr, int number_of_books) {
    books_merge_sort(book_db_ptr, 0, number_of_books - 1);
    for (int i = 0; i < number_of_books; i++)
        print_book_info(&book_db_ptr[i]);
}

void print_book_info(Book_t *book) {
    printf("ISBN: %lld\nAuthor: %s\nTitle: %s\nTotal number of books: %d\nTotal number of available books: %d\n",
           book->ISBN, book->author, book->title, book->total_books, book->available_books);
}

void edit_book_info(Book_t *book_db_ptr, int number_of_books, int number_of_students) {
    puts("Enter ISBN of a book you want to edit");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_students, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }
    bool running = true;
    while (running) {
        puts("Which book data do you want to change?\n1. Author\n2. Title\n3. Total available books");
        char input;
        int choice;
        int entry_count = 0;
        do {
            if (entry_count > 0)
                puts("Please enter a specified number as a choice");
            scanf("%s", &input);
            entry_count++;
        } while (!isdigit(input));
        switch (choice) {
            case AUTHOR:
                puts("Enter a new author");
                char *author = NULL;
                str_input(author, AUTHOR_SIZE);
                strcpy(book_db_ptr[index].author, author);
                break;
            case TITLE:
                puts("Enter a new title");
                char *title = NULL;
                str_input(title, TITLE_SIZE);
                strcpy(book_db_ptr[index].title, title);
                break;
            case TOTAL_BOOK_NUM:
                change_total_number_of_books(book_db_ptr, number_of_books);
                break;
            case BOOK_EDIT_EXIT:
                running = false;
                break;
            default:
                puts("Please enter a number specified in the edit menu");
                break;
        }
    }
}

void change_total_number_of_books(Book_t *book_db_ptr, int number_of_books) {
    puts("Enter ISBN of a book you want to change number of");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_books, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }
    int total_books;
    int tries_count = 0;
    do {
        if (tries_count > 0)
            puts("Total number of books cant be a negative number!");
        total_books = int_input();
        tries_count++;
    } while (total_books < 0);
    int delta = book_db_ptr[index].total_books - total_books;
    book_db_ptr[index].total_books = total_books;
    if (book_db_ptr[index].available_books + delta < 0)
        book_db_ptr[index].available_books = 0;
    else
        book_db_ptr[index].available_books += delta;
}

void give_a_book(Book_t *book_db_ptr, int number_of_books,
                 StudentBook_t *stud_book_db_ptr, int *number_of_student_books) {
    puts("Enter ISBN of a book you want to give");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_books, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }

    if (book_db_ptr[index].available_books == 0) {
        puts("There are no available books");
        return;
    }

    char *record_book_num = NULL;
    puts("Enter student's record book number");
    str_input(record_book_num, RECORD_BOOK_NUM_SIZE);

    char *return_date = NULL;
    puts("Enter return date of a book");
    str_input(return_date, RETURN_DATE_SIZE);

    book_db_ptr[index].available_books--;
    (*number_of_student_books)++;
    realloc(stud_book_db_ptr, *number_of_student_books);
    StudentBook_t book = {ISBN, record_book_num, return_date};
    stud_book_db_ptr[*number_of_student_books - 1] = book;
    puts("Book given successfully");
}

void receive_a_book(Book_t *book_db_ptr, int number_of_books,
                    StudentBook_t *stud_book_db_ptr, int *number_of_student_books) {
    puts("Enter ISBN of a book you want to receive");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_books, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }

    char *record_book_num = NULL;
    puts("Enter student's record book number");
    str_input(record_book_num, RECORD_BOOK_NUM_SIZE);

    if (book_db_ptr[index].available_books + 1 > book_db_ptr[index].total_books) {
        puts("Number of total books exceeded");
        return;
    }
    book_db_ptr[index].available_books++;

    for (int i = 0; i < *number_of_student_books; i++) {
        if (stud_book_db_ptr[i].ISBN == ISBN &&
            !strcmp(stud_book_db_ptr[i].record_book_num, record_book_num)) {
            for (int j = i; j < *number_of_student_books - 1; j++) {
                stud_book_db_ptr[i] = stud_book_db_ptr[i + 1];
            }
            free(stud_book_db_ptr[*number_of_student_books].record_book_num);
            free(stud_book_db_ptr[*number_of_student_books].return_date);
            (*number_of_student_books)--;
            return;
        }
    }
}