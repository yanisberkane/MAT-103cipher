/*
** EPITECH PROJECT, 2021
** cipher
** File description:
** get_matrix.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "../../include/cipher.h"

int my_strlen(char const *str);

int get_mat_lines(int nb, int col)
{
    if (nb % col != 0)
        return (nb / col + 1);
    return (nb / col);
}

int get_sqr_cols(int len)
{
    int col = sqrt(len);
    float fcol = sqrt(len);

    if (col != fcol)
        return col + 1;
    return col;
}

matrix get_n_matrix(char *str, int col)
{
    matrix mat;
    int len = my_strlen(str);
    int ind = 0;
    int col_pos = 0;

    mat.cols = col;
    mat.lines = get_mat_lines(len, col);
    mat.table = malloc(sizeof(int *) * mat.lines);
    for (int a = 0; a < mat.lines; a++) {
        mat.table[a] = malloc(sizeof(int) * mat.cols);
        for (col_pos = 0; col_pos < mat.cols && ind < len; col_pos++) {
            mat.table[a][col_pos] = str[ind];
            ind++;
            }
        }
    for (int p = col_pos; p < mat.cols; p++) {
        mat.table[mat.lines - 1][p] = 0;
    }
    return mat;
}

matrix get_matrix(char *str)
{
    matrix mtx;
    int len = my_strlen(str);
    int sqr_sum = my_compute_power_rec(get_sqr_cols(len), 2);
    int col_pos = 0;
    int ind = 0;

    mtx.lines = get_sqr_cols(len);
    mtx.cols = get_sqr_cols(len);
    mtx.table = malloc(sizeof(int *) * mtx.lines);
    for (int a = 0; a < mtx.lines; a++) {
        mtx.table[a] = malloc(sizeof(int) * mtx.cols);
        for (col_pos = 0; col_pos < mtx.cols && ind < len; col_pos++) {
            mtx.table[a][col_pos] = str[ind];
            ind++;
        }
    }
    for (int p = col_pos; p < mtx.cols; p++) {
        mtx.table[mtx.lines - 1][p] = 0;
    }
    return mtx;
}
