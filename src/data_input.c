#include "../include/data_input.h"

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