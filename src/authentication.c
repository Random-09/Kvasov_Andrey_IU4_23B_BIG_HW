#include "../include/authentication.h"

int login_index(const char *login, Users_t *users_ptr) {
    for (int i = 0; i < 50; i++) {
        if (!strcmp(login, users_ptr[i].login))
            return i;
    }
    return -1;
}

void str_input(char *input, int data_size) {
    int i = 0;
    do {
        if (i > 0)
            printf("Length must be equal or less than %d. Try again.\n", data_size);
        scanf("%s", input);
        i++;
    } while (strlen(input) > data_size);
}

void password_input(uint8_t hash[SIZE_OF_SHA_256_HASH]) {
    char password[PASSWORD_SIZE];
    str_input(password, PASSWORD_SIZE);
    calc_sha_256(hash, password, strlen(password));
}

void uint_to_str(uint8_t hash[], char hash_str[]) {
    for (int i = 0; i < 32; i++) {
        hash_str += sprintf(hash_str, "%02x", hash[i]);
    }
}

void authentication(Users_t *users_ptr) {
    char login[LOGIN_SIZE];
    uint8_t hash[SIZE_OF_SHA_256_HASH];
    char hash_str[HASH_STR_SIZE];
    puts("Enter student's login.");
    str_input(login, LOGIN_SIZE);
    int index = login_index(login, users_ptr);
    if (index == -1) {
        puts("This login is not found in database");
        return;
    }
    puts("Enter student's password.");
    password_input(hash);
    uint_to_str(hash, hash_str);
    if (!strcmp(users_ptr[index].hash, hash_str)) {
        puts("Authentication successful\n");
    } else
        puts("Wrong password\n");
}