/*
** EPITECH PROJECT, 2021
** my_putstr_err
** File description:
** Displays characters of a string in error output.
*/

#include <unistd.h>

int my_putstr_err(char const *str)
{
    int i;
    i = 0;
    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
    return (0);
}
