#include "../include/log.h"

void add_log(char *login, char *msg) {
    time_t current_time;
    struct tm* time_info;
    char time_string[MAX_DATE_SIZE];
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%d.%m.%Y %H:%M:%S", time_info);
    FILE *file_ptr = fopen(LOG_FILE_PATH, "a");
    fprintf(file_ptr, "%s,%s,%s\n", time_string, login, msg);
    fclose(file_ptr);
}