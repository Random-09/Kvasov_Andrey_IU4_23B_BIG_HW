#ifndef BIG_HW_AUTHENTICATION_H
#define BIG_HW_AUTHENTICATION_H

#include <stdio.h>
#include "init_db.h"
#include "../sha-2/sha-256.h"

#define NAME_SIZE 15
#define STUDENT_CARD_SIZE 7
#define LOGIN_SIZE 10
#define PASSWORD_SIZE 15
#define HASH_STR_SIZE 64
#define BUFFER 30
#define MAX_INT 9
#define MAX_FLOAT 7

int login_index(const char *login, User_t *user_db_ptr, int number_of_users);

void str_input(char *input, int data_size);

void password_input(uint8_t hash[SIZE_OF_SHA_256_HASH]);

void uint_to_str(uint8_t hash[], char hash_str[]);

int authentication(User_t *user_db_ptr, int number_of_users);


#endif
