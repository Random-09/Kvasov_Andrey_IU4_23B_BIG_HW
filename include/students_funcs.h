#ifndef BIG_HW_STUDENTS_FUNCS_H
#define BIG_HW_STUDENTS_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "init_db.h"
#include "data_input.h"

enum edit_choice {
    EXIT = 0,
    SURNAME,
    NAME,
    FACULTY,
    SPECIALITY
};

int student_index_by_record_book(Student_t *stud_db_ptr, int number_of_students, char *record_book_num);

void add_student(Student_t *stud_db_ptr, int *number_of_students);

void delete_student(Student_t *stud_db_ptr, int *number_of_students);

void edit_student_info(Student_t *stud_db_ptr, int number_of_students);

void show_student_info_by_record_book(Student_t *stud_db_ptr, int number_of_students);

void show_student_info_by_surname(Student_t *stud_db_ptr, int number_of_students);

void print_student_info(Student_t *student);

#endif
