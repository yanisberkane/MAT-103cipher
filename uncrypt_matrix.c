/*
** EPITECH PROJECT, 2021
** B-MAT-100-PAR-1-1-103cipher-yanis.berkane
** File description:
** uncrypt_matrix.c
*/

#include "include/cipher.h"
#include "include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

char *get_decrypted_phrase(matrix result)
{
    char *phrase;
    int ind = 0;

    phrase = malloc(sizeof(char) * (result.lines * result.cols) + 1);
    for (int i = 0; i < result.lines; i++) {
        for (int j = 0; j < result.cols; j++) {
            phrase[ind] = round(result.table[i][j]);
            ind++;
        }
    }
    return phrase;
}

int get_numberof_nbrs(char *str)
{
    int count = 1;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ' ')
            count++;
    }
    return count;
}

char **get_char_array(char *str, int s_nbrs)
{
    int ind = 0;
    char **numbers;
    int starter = 0;
    int nbrlen = 0;
    int i = 0;
    int j = 0;

    numbers = malloc(sizeof(char *) * s_nbrs + 1);
    for (i = 0; i < s_nbrs; i++) {
        for (int l = starter; str[l] != ' '; l++) {
            nbrlen = nbrlen + 1;
        }
        numbers[i] = malloc(sizeof(char) * nbrlen  + 1);
        for (j = 0; j < nbrlen; j++) {
            numbers[i][j] = str[ind];
            ind++;
            if (str[ind] == ' ') {
                ind++;
                break;
            }
        }
    }
    return numbers;
}

matrix get_crypted_matrix(char *str, int col)
{
    matrix mat;
    int s_nbrs = get_numberof_nbrs(str);
    char **nbrs = get_char_array(str, s_nbrs);
    int col_pos = 0;
    int id = 0;

    mat.cols = col;
    mat.lines = get_mat_lines(s_nbrs, col);
    mat.table = malloc(sizeof(float *) * mat.lines);
    for (int a = 0; a < mat.lines; a++) {
        mat.table[a] = malloc(sizeof(float) * mat.cols);
        for (col_pos = 0; col_pos < mat.cols && id < s_nbrs; col_pos++) {
            mat.table[a][col_pos] = atof(nbrs[id]);
            id++;
        }
    }
    for (int p = col_pos; p < mat.cols; p++) {
        mat.table[mat.lines - 1][p] = 0;
    }
    return mat;
}

matrix get_1x1_direct(matrix mat)
{
    matrix revd;

    revd.lines = mat.lines;
    revd.cols = mat.cols;
    revd.table = malloc(sizeof(float));
    revd.table[0] = malloc(sizeof(float));
    revd.table[0][0] = 1 / mat.table[0][0];

    return revd;
}

matrix get_3x3_cofactor(matrix mat)
{
    matrix cofactor;

    cofactor.lines = 3;
    cofactor.cols = 3;
    cofactor.table = malloc(sizeof(float *) * 3);
    for (int i = 0; i < 3; i++)
        cofactor.table[i] = malloc(sizeof(float) * 3);
    cofactor.table[0][0] = mat.table[1][1] * mat.table[2][2] - mat.table[1][2] * mat.table[2][1];
    cofactor.table[0][1] = mat.table[1][2] * mat.table[2][0] - mat.table[1][0] * mat.table[2][2];
    cofactor.table[0][2] = mat.table[1][0] * mat.table[2][1] - mat.table[1][1] * mat.table[2][0];
    cofactor.table[1][0] = -1 * (mat.table[0][1] * mat.table[2][2] - mat.table[0][2] * mat.table[2][1]);
    cofactor.table[1][1] = mat.table[0][0] * mat.table[2][2] - mat.table[0][2] * mat.table[2][0];
    cofactor.table[1][2] = mat.table[0][1] * mat.table[2][0] - mat.table[0][0] * mat.table[2][1];
    cofactor.table[2][0] = mat.table[0][1] * mat.table[1][2] - mat.table[0][2] * mat.table[1][1];
    cofactor.table[2][1] = mat.table[0][2] * mat.table[1][0] - mat.table[0][0] * mat.table[1][2];
    cofactor.table[2][2] = mat.table[0][0] * mat.table[1][1] - mat.table[0][1] * mat.table[1][0];

    return cofactor;
}

matrix mul_reversed_mat(matrix mat, float det)
{
    matrix res;

    if (det != 0) {
        res.lines = mat.lines;
        res.cols = mat.cols;
        res.table = malloc(sizeof(float *) * mat.lines);
        for (int i = 0; i < mat.lines; i++) {
            res.table[i] = malloc(sizeof(float) * mat.cols);
            for (int j = 0; j < mat.cols; j++) {
                res.table[i][j] = mat.table[i][j] / det;
            }
        }
        return res;
    }
    res.table = NULL;
    res.lines = 0;
    res.cols = 0;
    return res;
}

float get_mat_determinant(matrix mat, matrix cofact)
{
    float dmt = 0;

    if (mat.lines == 2 && mat.cols == 2) {
        dmt = mat.table[0][0] * mat.table[1][1] - mat.table[0][1] * mat.table[1][0];
        return dmt;
    }
    if (mat.lines == 3 && mat.cols == 3) {
        for (int i = 0; i < cofact.cols; i++) {
            dmt = cofact.table[0][i] * mat.table[0][i] + dmt;
        }
        return dmt;
    }
    return 0;
}

matrix transpose_matrix(matrix mat)
{
    matrix transp_m;

    transp_m.lines = mat.cols;
    transp_m.cols = mat.lines;
    transp_m.table = malloc(sizeof(int *) * transp_m.lines);
    for (int i = 0; i < transp_m.lines; i++) {
        transp_m.table[i] = malloc(sizeof(int) * transp_m.cols);
        for (int j = 0; j < transp_m.cols; j++) {
            transp_m.table[i][j] = mat.table[j][i];
        }
    }
    return transp_m;
}

matrix get_2x2_transposed_mtx(matrix cofact)
{
    matrix mat;

    mat.lines = cofact.cols;
    mat.cols = cofact.lines;
    mat.table = malloc(sizeof(float *) * mat.lines);
    for (int i = 0; i < mat.lines; i++) {
        mat.table[i] = malloc(sizeof(float) * mat.cols);
    }
    mat.table[0][0] = cofact.table[1][1];
    mat.table[0][1] = (cofact.table[0][1]) * -1;
    mat.table[1][0] = (cofact.table[1][0]) * -1;
    mat.table[1][1] = cofact.table[0][0];
    return mat;
}

matrix get_cofactor_matrix(matrix key)
{
    matrix rev;
    float det;
    matrix res;
    matrix cofact;

    if (key.lines == 1 && key.cols == 1) {
        res = get_1x1_direct(key);
        return res;
    }
    if ((key.lines == 2 && key.cols == 2)) {
        cofact = key;
        rev = get_2x2_transposed_mtx(cofact);
    }
    if (key.lines == 3 && key.cols == 3) {
        cofact = get_3x3_cofactor(key);
        rev = transpose_matrix(cofact);
    }
    if ((cofact.lines == 2 && cofact.cols == 2) || (cofact.lines == 3 && cofact.cols == 3)) {
        det = get_mat_determinant(key, cofact);
        if (det == 0) {
            res.table = NULL;
            res.lines = 84;
            res.cols = 84;
            return res;
        }
        res = mul_reversed_mat(rev, det);
        return res;
    }
    res.lines = 0;
    res.cols = 0;
    res.table = NULL;
    return res;
}
