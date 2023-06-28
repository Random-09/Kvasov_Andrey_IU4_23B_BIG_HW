#include "../include/authentication.h"

int login_index(const char *login, User_t *user_db_ptr, int number_of_users) {
    for (int i = 0; i < number_of_users; i++) {
        if (!strcmp(login, user_db_ptr[i].login))
            return i;
    }
    return -1;
}

int authentication(User_t *user_db_ptr, int number_of_users) {
    char login[LOGIN_SIZE];
    uint8_t hash[SIZE_OF_SHA_256_HASH];
    char hash_str[HASH_STR_SIZE];
    puts("Enter student's login.");
    str_input(login, LOGIN_SIZE);
    int index = login_index(login, user_db_ptr, number_of_users);
    if (index == -1) {
        puts("This login is not found in database");
        return -1;
    }
    puts("Enter student's password.");
    password_input(hash);
    uint_to_str(hash, hash_str);
    if (!strcmp(user_db_ptr[index].hash, hash_str)) {
        return index;
    } else {
        puts("Wrong password\n");
        return -1;
    }
}
