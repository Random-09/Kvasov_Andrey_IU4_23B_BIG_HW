#ifndef BIG_HW_AUTHENTICATION_H
#define BIG_HW_AUTHENTICATION_H

#include <stdio.h>
#include <stdint.h>
#include "init_db.h"
#include "data_input.h"

#define PASSWORD_SIZE 15
#define LOGIN_SIZE 10
#define HASH_STR_SIZE 64

int login_index(const char *login, User_t *user_db_ptr, int number_of_users);

int authentication(User_t *user_db_ptr, int number_of_users);

#endif
