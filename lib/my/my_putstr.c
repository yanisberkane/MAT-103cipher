/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Displays characters of a string.
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i;
    i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
