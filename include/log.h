#ifndef BIG_HW_LOG_H
#define BIG_HW_LOG_H

#include <stdio.h>
#include <time.h>

#define LOG_FILE_PATH "../log/library.log"

#define MAX_DATE_SIZE 20

void add_log(char *login, char *msg);

#endif
