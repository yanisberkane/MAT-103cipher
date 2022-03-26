/*
** EPITECH PROJECT, 2021
** 103cipher
** File description:
** main.c
*/

#include "include/cipher.h"
#include "include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

int is_digits(char *argv)
{
    for (int i = 0; i < my_strlen(argv); i++) {
        if ((argv[i] < '0' || argv[i] > '9') && argv[i] != '-' && argv[i] != ' ') {
            return 1;
        }
    }
    return 0;
}

void print_decryption_result(char *c_result, matrix key)
{
    int spacer = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < key.lines; i++) {
        for (int j = 0; j < key.cols; j++) {
            if (spacer != 0)
                printf("\t");
            if (key.table[i][j] == 0)
                printf("0.0");
            else
                printf("%.3f", key.table[i][j]);
            spacer++;
        }
    printf("\n");
    spacer = 0;
    }
    printf("\nDecrypted message:\n%s\n", c_result);
}

void print_encryption_result(matrix result, matrix key)
{
    int spacer = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < key.lines; i++) {
        for (int j = 0; j < key.cols; j++) {
            if (spacer != 0)
                printf("\t");
            printf("%.0f", key.table[i][j]);
            spacer++;
        }
    printf("\n");
    spacer = 0;
    }
    printf("\nEncrypted message:\n");
    for (int i = 0; i < result.lines; i++) {
        for (int j = 0; j < result.cols; j++) {
            if (spacer != 0)
                printf(" ");
            printf("%.0f", result.table[i][j]);
            spacer++;
        }
    }
    printf("\n");
}

int get_msg(char *c_phrase, char *c_key, int type)
{
    matrix phrase;
    matrix key;
    matrix cofactor;
    matrix result;
    char *c_result;

    key = get_matrix(c_key);
    if (type == 0) {
        phrase = get_n_matrix(c_phrase, key.lines);
        result = mat_mul(phrase, key);
        print_encryption_result(result, key);
    }
    if (type == 1) {
        phrase = get_crypted_matrix(c_phrase, key.lines);
        cofactor = get_cofactor_matrix(key);
        if (cofactor.table == NULL)
            return 84;
        result = mat_mul(phrase, cofactor);
        c_result = get_decrypted_phrase(result);
        print_decryption_result(c_result, cofactor);
    }
    free(key.table);
    free(phrase.table);
    free(result.table);
    if (type == 1) {
        free(cofactor.table);
        free(c_result);
    }
    return 0;
}

int main(int argc, char **argv)
{
    int check_err = 0;
    if (argc != 4) {
        if (argc == 2 && strcmp(argv[1], "-h") == 0) {
            my_putstr(USER_MANUAL);
            return 0;
        }
        my_putstr_err(ERROR_MSG);
        return ERROR;
    }
    if (strcmp(argv[3], "0") == 0 || strcmp(argv[3], "1") == 0) {
        if (strcmp(argv[3], "1") == 0 && is_digits(argv[1]) == 1) {
            my_putstr_err(ERROR_MSG);
            return ERROR;
        }
        check_err = get_msg(argv[1], argv[2], my_getnbr(argv[3]));
    } else {
        my_putstr_err(ERROR_MSG);
        return ERROR; 
    }
    return check_err;
}
