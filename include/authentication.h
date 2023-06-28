#ifndef BIG_HW_AUTHENTICATION_H
#define BIG_HW_AUTHENTICATION_H

#include <stdio.h>
#include <stdint.h>
#include "init_db.h"
#include "../sha-2/sha-256.h"
#include "data_input.h"

#define LOGIN_SIZE 10
#define HASH_STR_SIZE 64

int login_index(const char *login, User_t *user_db_ptr, int number_of_users);

int authentication(User_t *user_db_ptr, int number_of_users);


#endif
