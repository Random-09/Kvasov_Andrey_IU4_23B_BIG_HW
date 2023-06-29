#include "../include/students_funcs.h"

int student_index_by_record_book(Student_t *stud_db_ptr, int number_of_students, char *record_book_num) {
    for (int i = 0; i < number_of_students; i++) {
        if (!strcmp(record_book_num, stud_db_ptr[i].record_book_num))
            return i;
    }
    return -1;
}

void add_student(Student_t *stud_db_ptr, int *number_of_students) {
    char *record_book_num = (char *) malloc(RECORD_BOOK_NUM_SIZE * sizeof(char));
    puts("Enter student's record book number");
    str_input(record_book_num, RECORD_BOOK_NUM_SIZE);

    if (student_index_by_record_book(stud_db_ptr, *number_of_students, record_book_num) != -1) {
        puts("Student with this record book number is already in the database");
        return;
    }

    char *surname = (char *) malloc(SURNAME_SIZE * sizeof(char ));
    puts("Enter student's surname");
    str_input(surname, SURNAME_SIZE);

    char *name = (char *) malloc(NAME_SIZE * sizeof(char ));
    puts("Enter student's name");
    str_input(name, NAME_SIZE);

    char *faculty = (char *) malloc(FACULTY_SIZE * sizeof(char ));
    puts("Enter student's faculty");
    str_input(faculty, FACULTY_SIZE);

    char *speciality = (char *) malloc(SPECIALITY_SIZE * sizeof(char ));
    puts("Enter student's speciality");
    str_input(speciality, SPECIALITY_SIZE);

    (*number_of_students)++;
    realloc(stud_db_ptr, *number_of_students);
    Student_t student = {record_book_num, surname, name, faculty, speciality};
    stud_db_ptr[*number_of_students - 1] = student;
    puts("Student added successfully!");
}

void delete_student(Student_t *stud_db_ptr, int *number_of_students,
                    StudentBook_t *stud_book_db_ptr, int number_of_student_books) {
    char *record_book_num = NULL;
    puts("Enter record book number of a student you want to delete");
    str_input(record_book_num, RECORD_BOOK_NUM_SIZE);

    int index = student_index_by_record_book(stud_db_ptr, *number_of_students, record_book_num);
    if (index == -1) {
        puts("This student is not in the database");
        return;
    }

    for (int i = 0; i < number_of_student_books; i++) {
        if (!strcmp(stud_book_db_ptr[i].record_book_num, record_book_num)) {
            puts("Cant delete this student, because he has books");
            return;
        }
    }

    for (int i = index; i < *number_of_students - 1; i++) {
        stud_db_ptr[i] = stud_db_ptr[i + 1];
    }
    free(stud_db_ptr[*number_of_students].record_book_num);
    free(stud_db_ptr[*number_of_students].surname);
    free(stud_db_ptr[*number_of_students].name);
    free(stud_db_ptr[*number_of_students].faculty);
    free(stud_db_ptr[*number_of_students].speciality);
    (*number_of_students)--;
}

void edit_student_info(Student_t *stud_db_ptr, int number_of_students) {
    char *record_book_num = NULL;
    puts("Enter record book number of a student you want to edit");
    str_input(record_book_num, RECORD_BOOK_NUM_SIZE);
    int index = student_index_by_record_book(stud_db_ptr, number_of_students, record_book_num);
    if (index == -1) {
        puts("This student is not in the database");
        return;
    }
    bool running = true;
    while (running) {
        puts("Which student data do you want to change?\n1. Surname\n2. Name\n3. Faculty\n4. Speciality\n");
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
            case SURNAME:
                puts("Enter a new surname");
                char *surname = NULL;
                str_input(surname, SURNAME_SIZE);
                strcpy(stud_db_ptr[index].surname, surname);
                break;
            case NAME:
                puts("Enter a new name");
                char *name = NULL;
                str_input(name, NAME_SIZE);
                strcpy(stud_db_ptr[index].name, name);
                break;
            case FACULTY:
                puts("Enter a new faculty");
                char *faculty = NULL;
                str_input(faculty, FACULTY_SIZE);
                strcpy(stud_db_ptr[index].faculty, faculty);
                break;
            case SPECIALITY:
                puts("Enter a new speciality");
                char *speciality = NULL;
                str_input(speciality, SPECIALITY_SIZE);
                strcpy(stud_db_ptr[index].speciality, speciality);
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

void show_student_info_by_record_book(Student_t *stud_db_ptr, int number_of_students,
                                      StudentBook_t *stud_book_db_ptr, int number_of_student_books,
                                      Book_t *book_db_ptr, int number_of_books) {
    puts("Enter a record book number of a student you want to see");
    char *record_book_num = NULL;
    str_input(record_book_num, RECORD_BOOK_NUM_SIZE);
    int index = student_index_by_record_book(stud_db_ptr, number_of_students, record_book_num);
    if (index == -1) {
        puts("This student is not in the database");
        return;
    }
    print_student_info(&stud_db_ptr[index]);

    puts("Books of this student:");
    for (int i = 0; i < number_of_student_books; i++) {
        if (!strcmp(stud_book_db_ptr[i].record_book_num, record_book_num)) {
            for (int j = 0; j < number_of_books; j++) {
                if (stud_book_db_ptr[i].ISBN == book_db_ptr[j].ISBN)
                    printf("%s %s", book_db_ptr[j].title, book_db_ptr[j].author);
            }
        }
    }
}

void show_student_info_by_surname(Student_t *stud_db_ptr, int number_of_students) {
    bool students_found = false;
    puts("Enter a surname of student/students you want to find");
    char *surname = NULL;
    str_input(surname, SURNAME_SIZE);
    for (int i = 0; i < number_of_students; i++) {
        if (!strcmp(surname, stud_db_ptr[i].surname)) {
            students_found = true;
            print_student_info(&stud_db_ptr[i]);
        }
    }
    if (!students_found)
        puts("No students with this surname in the database");
}

void print_student_info(Student_t *student) {
    printf("Record book number %s\nSurname: %s\nName: %s\nFaculty: %s\nSpeciality: %s",
           student->record_book_num, student->surname, student->name,
           student->faculty, student->speciality);
}