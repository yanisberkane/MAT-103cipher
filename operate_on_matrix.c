/*
** EPITECH PROJECT, 2021
** B-MAT-100-PAR-1-1-103cipher-yanis.berkane
** File description:
** operate_on_matrix.c
*/

#include "include/cipher.h"
#include "include/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

matrix mat_mul(matrix m1, matrix m2)
{
    matrix res;
    float sum = 0;

    res.lines = m1.lines;
    res.cols = m2.cols;
    res.table = malloc(sizeof(float *) * m1.lines);
    for (int i = 0; i < m1.lines; i++) {
        res.table[i] = malloc(sizeof(float) * m2.cols);
        for (int j = 0; j < m2.cols; j++) {
            for (int k = 0; k < m2.lines; k++) {
                sum = sum + m1.table[i][k] * m2.table[k][j];
                res.table[i][j] = sum;
            }
            sum = 0;
            }
        }
    return res;
}
