#include "../include/save_and_free_db.h"

void save_books(Book_t *book_db_ptr, int number_of_books) {
    FILE *file_ptr = fopen(BOOKS_DB_FILE_PATH, "w");
    for (int i = 0; i < number_of_books; i++) {
        fprintf(file_ptr, "%lld,%s,%s,%d,%d", book_db_ptr[i].ISBN, book_db_ptr[i].author,
                book_db_ptr[i].title, book_db_ptr[i].total_books, book_db_ptr[i].available_books);
        if (i != number_of_books - 1)
            fputs("\n", file_ptr);
    }
    fclose(file_ptr);
}

void save_students(Student_t *stud_db_ptr, int number_of_students) {
    FILE *file_ptr = fopen(STUDENTS_DB_FILE_PATH, "w");
    for (int i = 0; i < number_of_students; i++) {
        fprintf(file_ptr, "%s,%s,%s,%s,%s", stud_db_ptr[i].record_book_num,
                stud_db_ptr[i].surname, stud_db_ptr[i].name, stud_db_ptr[i].faculty, stud_db_ptr[i].speciality);
    }
    fclose(file_ptr);
}

void save_student_books(StudentBook_t *stud_book_db_ptr, int number_of_student_books) {
    FILE *file_ptr = fopen(STUDENTS_BOOKS_DB_FILE_PATH, "w");
    for (int i = 0; i < number_of_student_books; i++) {
        printf("%lld,%s,%s", stud_book_db_ptr[i].ISBN, stud_book_db_ptr[i].record_book_num,
                stud_book_db_ptr[i].return_date);
        fprintf(file_ptr, "%lld,%s,%s", stud_book_db_ptr[i].ISBN, stud_book_db_ptr[i].record_book_num,
                stud_book_db_ptr[i].return_date);
    }
    fclose(file_ptr);
}

void free_books_db(Book_t *book_db_ptr, int number_of_books) {
    for (int i = 0; i < number_of_books; i++) {
        free(book_db_ptr[i].title);
        free(book_db_ptr[i].author);
    }
    free(book_db_ptr);
}

void free_students_db(Student_t *stud_db_ptr, int number_of_students) {
    for (int i = 0; i < number_of_students; i++) {
        free(stud_db_ptr[i].record_book_num);
        free(stud_db_ptr[i].surname);
        free(stud_db_ptr[i].name);
        free(stud_db_ptr[i].faculty);
        free(stud_db_ptr[i].speciality);
    }
    free(stud_db_ptr);
}

void free_users_db(User_t *user_db_ptr, int number_of_users) {
    for (int i = 0; i < number_of_users; i++) {
        free(user_db_ptr[i].login);
        free(user_db_ptr[i].hash);
    }
    free(user_db_ptr);
}

void free_student_book_db(StudentBook_t *stud_book_db_ptr, int number_of_student_books) {
    for (int i = 0; i < number_of_student_books; i++) {
        free(stud_book_db_ptr[i].record_book_num);
        free(stud_book_db_ptr[i].return_date);
    }
    free(stud_book_db_ptr);
}