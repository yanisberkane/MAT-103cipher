/*
** EPITECH PROJECT, 2021
** cipher_h
** File description:
** Library header
*/

#ifndef MATRIX_H
    #define MATRIX_H

    typedef struct fmat matrix;
    struct fmat {
        float **table;
        int lines;
        int cols;
    };

#endif

#ifndef CIPHER_H
    #define CIPHER_H

    #define ERROR 84
    #define MY_PI 3.14159265358979323846
    #define ERROR_MSG "error\n"
    #define FILE_ERROR_MSG "file format error\n"
    #define EXIT_USAGE    0
    #define USER_MANUAL "USAGE\n\
    ./103cipher message key flag\n\
DESCRIPTION\n\
    message     a message, made of ASCII characters\n\
    key         the encryption key, made of ASCII characters\n\
    flag        0 for the message to be encrypted, 1 to be decrypted\n"

matrix get_cofactor_matrix(matrix key);
matrix transpose_matrix(matrix mat);
float get_mat_determinant(matrix mat, matrix cofact);
matrix mul_reversed_mat(matrix mat, float det);
matrix get_3x3_cofactor(matrix mat);
matrix get_crypted_matrix(char *str, int col);
char *get_decrypted_phrase(matrix result);

#endif
