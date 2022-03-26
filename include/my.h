/*
** EPITECH PROJECT, 2021
** my_h
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

#ifndef MY_H
    #define MY_H

int my_putstr_err(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int put_base_nbr(unsigned int nb, unsigned int base);
int my_compute_power_rec(int nb, int p);
char *isole_nbr_in_str(char const *str);
matrix get_matrix(char *str);
matrix get_n_matrix(char *str, int col);
matrix mat_mul(matrix m1, matrix m2);
matrix reverse_matrix(matrix key);
int get_mat_lines(int nb, int col);

#endif
