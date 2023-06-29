#include "../include/book_sort.h"

void merge(Book_t *array, int left, int middle, int right) {
    int i, j, k;
    int left_len = middle - left + 1;
    int right_len = right - middle;
    Book_t left_array[left_len], right_array[right_len];
    for (i = 0; i < left_len; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < right_len; j++)
        right_array[j] = array[middle + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < left_len && j < right_len) {
        if (left_array[i].ISBN <= right_array[j].ISBN) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_len) {
        array[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_len) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void books_merge_sort(Book_t *array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        books_merge_sort(array, left, middle);
        books_merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}