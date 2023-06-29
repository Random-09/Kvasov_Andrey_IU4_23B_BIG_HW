#include "../include/init_db.h"

Student_t *init_students_db(int *number_of_students) {
    Student_t *stud_db_ptr = (Student_t *) malloc(sizeof(Student_t) * STUDENTS_DB_CAPACITY);
    FILE *file_ptr = fopen(STUDENTS_DB_FILE_PATH, "r");
    char line[MAX_LINE_LEN];
    char *record_book_num_tok, *surname_tok, *name_tok, *faculty_tok, *speciality_tok;
    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        if (*number_of_students == STUDENTS_DB_CAPACITY) {
            puts("Students db capacity reached");
            add_log("non authorised", "Error: Students db capacity reached");
            exit(EXIT_FAILURE);
        }
        record_book_num_tok = strtok(line, ",");
        surname_tok = strtok(NULL, ",");
        name_tok = strtok(NULL, ",");
        faculty_tok = strtok(NULL, ",");
        speciality_tok = strtok(NULL, ",");

        char *record_book_num, *surname, *name, *faculty, *speciality;
        record_book_num = (char *) malloc(strlen(record_book_num_tok) * sizeof(char ));
        surname = (char *) malloc(strlen(surname_tok) * sizeof(char));
        name = (char *) malloc(strlen(name_tok) * sizeof(char));
        faculty = (char *) malloc(strlen(faculty_tok) * sizeof(char ));
        speciality = (char *) malloc(strlen(speciality_tok) * sizeof(char ));

        strcpy(record_book_num, record_book_num_tok);
        strcpy(surname, surname_tok);
        strcpy(name, name_tok);
        strcpy(faculty, faculty_tok);
        strcpy(speciality, speciality_tok);

        Student_t student = {record_book_num, surname, name, faculty, speciality};
        stud_db_ptr[*number_of_students] = student;
        (*number_of_students)++;
    }
    fclose(file_ptr);
    return stud_db_ptr;
}

Book_t *init_books_db (int *number_of_books) {
    Book_t *book_db_ptr = (Book_t *) malloc(sizeof(Book_t) * BOOKS_DB_CAPACITY);
    FILE *file_ptr = fopen(BOOKS_DB_FILE_PATH, "r");
    char line[MAX_LINE_LEN];
    char *ISBN_tok, *author_tok, *title_tok, *total_books_tok, *available_books_tok;
    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        if (*number_of_books == BOOKS_DB_CAPACITY) {
            puts("Books db capacity reached");
            add_log("non authorised", "Error: Books db capacity reached");
            exit(EXIT_FAILURE);
        }
        ISBN_tok = strtok(line, ",");
        author_tok = strtok(NULL, ",");
        title_tok = strtok(NULL, ",");
        total_books_tok = strtok(NULL, ",");
        available_books_tok = strtok(NULL, ",");

        char *author, *title;
        author = (char *) malloc(strlen(author_tok) * sizeof(char ));
        title = (char *) malloc(strlen(title_tok) * sizeof(char));

        strcpy(author, author_tok);
        strcpy(title, title_tok);

        long long ISBN = atoll(ISBN_tok);
        int total_books = atoi(total_books_tok);
        int available_books = atoi(available_books_tok);

        Book_t book = {ISBN, author, title, total_books, available_books};
        book_db_ptr[*number_of_books] = book;
        (*number_of_books)++;
    }
    fclose(file_ptr);
    return book_db_ptr;
}

User_t *init_users_db(int *number_of_users) {
    User_t *user_db_ptr = (User_t *) malloc(sizeof(User_t) * USERS_DB_CAPACITY);
    FILE *file_ptr = fopen(USERS_DB_FILE_PATH, "r");
    char line[MAX_LINE_LEN];
    char *login_tok, *hash_tok, *full_student_access_tok, *full_books_access_tok;
    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        if (*number_of_users == USERS_DB_CAPACITY) {
            puts("Users db capacity reached");
            add_log("non authorised", "Error: Users db capacity reached");
            exit(EXIT_FAILURE);
        }
        login_tok = strtok(line, ",");
        hash_tok = strtok(NULL, ",");
        full_student_access_tok = strtok(NULL, ",");
        full_books_access_tok = strtok(NULL, ",");

        char *login, *hash;
        login = (char *) malloc(strlen(login_tok) * sizeof(char ));
        hash = (char *) malloc(strlen(hash_tok) * sizeof(char));

        strcpy(login, login_tok);
        strcpy(hash, hash_tok);

        bool full_student_access = atoi(full_student_access_tok);
        bool full_books_access = atoi(full_books_access_tok);

        User_t user = {login, hash, full_student_access, full_books_access};
        user_db_ptr[*number_of_users] = user;
        (*number_of_users)++;
    }
    fclose(file_ptr);
    return user_db_ptr;
}

StudentBook_t *init_student_book_db(int *number_of_student_books) {
    StudentBook_t *stud_book_db_ptr = (StudentBook_t *) malloc(sizeof(StudentBook_t) * STUDENT_BOOKS_DB_CAPACITY);
    FILE *file_ptr = fopen(STUDENTS_BOOKS_DB_FILE_PATH, "r");
    char line[MAX_LINE_LEN];
    char *ISBN_tok, *record_book_num_tok, *return_date_tok;
    while (fgets(line, MAX_LINE_LEN, file_ptr) != NULL) {
        if (*number_of_student_books == STUDENT_BOOKS_DB_CAPACITY) {
            puts("Students books db capacity reached");
            add_log("non authorised", "Error: Students books db capacity reached");
            exit(EXIT_FAILURE);
        }
        ISBN_tok = strtok(line, ",");
        record_book_num_tok = strtok(NULL, ",");
        return_date_tok = strtok(NULL, ",");

        char *record_book_num, *return_date;
        record_book_num = (char *) malloc(strlen(record_book_num_tok) * sizeof(char ));
        return_date = (char *) malloc(strlen(return_date_tok) * sizeof(char));

        strcpy(record_book_num, record_book_num_tok);
        strcpy(return_date, return_date_tok);

        long long ISBN = atoll(ISBN_tok);

        StudentBook_t student_book = {ISBN, record_book_num, return_date};
        stud_book_db_ptr[*number_of_student_books] = student_book;
        (*number_of_student_books)++;
    }
    fclose(file_ptr);
    return stud_book_db_ptr;
}