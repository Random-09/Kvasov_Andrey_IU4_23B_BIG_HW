#ifndef BIG_HW_DATA_INPUT_H
#define BIG_HW_DATA_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../sha-2/sha-256.h"

#define RECORD_BOOK_NUM_SIZE 7
#define SURNAME_SIZE 15
#define NAME_SIZE 15
#define FACULTY_SIZE 5
#define SPECIALITY_SIZE 30
#define PASSWORD_SIZE 15
#define BUFFER 30
#define MAX_INT 9
#define MAX_FLOAT 7

void str_input(char *input, int data_size);

void password_input(uint8_t hash[SIZE_OF_SHA_256_HASH]);

void uint_to_str(uint8_t hash[], char hash_str[]);

#endif
