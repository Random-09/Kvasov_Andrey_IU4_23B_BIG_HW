#include "../include/book_funcs.h"

int book_index_by_isbn(Book_t *book_db_ptr, int number_of_books, long ISBN) {
    for (int i = 0; i < number_of_books; i++) {
        if (book_db_ptr[i].ISBN == ISBN)
            return i;
    }
    return -1;
}

void add_book(Book_t *book_db_ptr, int *number_of_books) {
    puts("Enter ISBN of a book");
    long ISBN = long_input();

    if (book_index_by_isbn(book_db_ptr, *number_of_books, ISBN) != -1) {
        puts("Student with this record book number is already in the database");
        return;
    }

    puts("Enter author of a book");
    char *author = (char *) malloc(AUTHOR_SIZE * sizeof(char ));
    str_input(author, AUTHOR_SIZE);

    puts("Enter title of a book");
    char *title = (char *) malloc(TITLE_SIZE * sizeof(char ));
    str_input(title, TITLE_SIZE);

    puts("Enter total number of books");
    int total_books = int_input();

    puts("Enter number of available books");
    int available_books = int_input();

    (*number_of_books)++;
    realloc(book_db_ptr, *number_of_books);
    Book_t book = {ISBN, author, title, total_books, available_books};
    book_db_ptr[*number_of_books - 1] = book;
    puts("Book added successfully!");
}

void delete_book(Book_t *book_db_ptr, int *number_of_books) {
    puts("Enter ISBN of a book you want to delete");
    long ISBN = long_input();
    // ПРОВЕРКА НА ТО, ЧТО ЭТОЙ КНИГИ НЕТУ У СТУДЕНТОВ                  <<-----
    // ПРОВЕРКА НА ТО, ЧТО ЭТОЙ КНИГИ НЕТУ У СТУДЕНТОВ                  <<-----
    // ПРОВЕРКА НА ТО, ЧТО ЭТОЙ КНИГИ НЕТУ У СТУДЕНТОВ                  <<-----
    // ПРОВЕРКА НА ТО, ЧТО ЭТОЙ КНИГИ НЕТУ У СТУДЕНТОВ                  <<-----
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
    // realloc cannot decrease book_db memory correctly :(
}

void book_info(Book_t *book_db_ptr, int number_of_books) {
    puts("Enter ISBN of a book you want to see");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_books, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }
    print_book_info(&book_db_ptr[index]);

    // ДОДЕЛАТЬ ВЫВОД ПРО СТУДЕНТОВ, ВЗЯВШИХ КНИГУ                  <<------
    // ДОДЕЛАТЬ ВЫВОД ПРО СТУДЕНТОВ, ВЗЯВШИХ КНИГУ                  <<------
    // ДОДЕЛАТЬ ВЫВОД ПРО СТУДЕНТОВ, ВЗЯВШИХ КНИГУ                  <<------
    // ДОДЕЛАТЬ ВЫВОД ПРО СТУДЕНТОВ, ВЗЯВШИХ КНИГУ                  <<------
}

void all_books_info(Book_t *book_db_ptr, int number_of_books) {
    books_merge_sort(book_db_ptr, 0, number_of_books - 1);
    for (int i = 0; i < number_of_books; i++)
        print_book_info(&book_db_ptr[i]);
}

void print_book_info(Book_t *book) {
    printf("ISBN: %ld\nAuthor: %s\nTitle %s\nTotal number of books: %d\nTotal number of available books: %d",
           book->ISBN, book->author, book->title, book->total_books, book->available_books);
}

void edit_book_info(Book_t *book_db_ptr, int number_of_students) {
    puts("Enter ISBN of a book you want to edit");
    long ISBN = long_input();
    int index = book_index_by_isbn(book_db_ptr, number_of_students, ISBN);
    if (index == -1) {
        puts("This book is not in the database");
        return;
    }
    bool running = true;
    while (running) {
        puts("Which book data do you want to change?\n1. Author\n2. Title\n3. Total available books\n");
        char input;
        int choice;
        int entry_count = 0;
        do {
            if (entry_count > 0)
                puts("Please enter a specified number as a choice");
            scanf("%c", &input);
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
                // independent function in progress                         <<------
                break;
            case EXIT:
                running = false;
                break;
            default:
                puts("Please enter a number specified in the edit menu");
                break;
        }
    }
}

void change_total_number_of_books(Book_t *book_db_ptr, int number_of_books) {       //      <<< total_num > 0 >>>
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

}

void give_a_book(Book_t *book_db_ptr, int number_of) {}