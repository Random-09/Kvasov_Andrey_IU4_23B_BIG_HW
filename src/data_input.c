#include "../include/data_input.h"

int int_check(char *data) {
    for (int i = 0; i < strlen(data); i++) {
        if (!isdigit(data[i]))
            return 0;
    }
    return 1;
}

int int_input() {
    char *input = NULL;
    int tries_count = 0;                                  // <---- change i to tries_count or smth idk
    do {
        if (tries_count > 0)
            printf("This value is not a number or longer than %d. Try again.\n", MAX_INT_SIZE);
        scanf("%s", input);
        tries_count++;
    } while (!int_check(input) || strlen(input) > MAX_INT_SIZE);
    return atoi(input);
}

long long_input() {
    char *input = NULL;
    int tries_count = 0;
    do {
        if (tries_count > 0)
            printf("This value is not a number or longer than %d. Try again.\n", MAX_LONG_SIZE);
        scanf("%s", input);
        tries_count++;
    } while (!int_check(input) || strlen(input) > MAX_LONG_SIZE);
    return atol(input);
}

void str_input(char *input, int data_size) {
    int tries_count = 0;
    do {
        if (tries_count > 0)
            printf("Length must be equal or less than %d. Try again.\n", data_size);
        scanf("%s", input);
        tries_count++;
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