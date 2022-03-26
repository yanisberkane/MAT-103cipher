/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** getnbr
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

int my_isnotdigit(char const *str, int i)
{
    int j = i + 1;

    if ((str[i + 1] < '0' || str[i + 1] > '9'))
        return 1;
    return 0;
}

char *isole_nbr_in_str(char const *str)
{
    char *st;
    int j = 0;

    st = malloc(sizeof(int) * my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            st[j] = str[i];
            j++;
        }
        if (my_isnotdigit(str, i) == 1 && str[i + 1] != '-'
            && str[i + 1] != '+')
            break;
    }
    return st;
}

int minus_detector(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            return 1;
    }
    return 0;
}

int check_integer(char const *str, int nb)
{
    if (nb < 0 && minus_detector(str) == 0)
        return 0;
    if (nb > 0 && minus_detector(str) == 1)
        return 0;
    return nb;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int factor = 10;
    char *nb_str;
    int l;
    int res;

    nb_str = isole_nbr_in_str(str);
    l = my_strlen(nb_str);
    for (int k = 0; nb_str[k] != '\0'; k++) {
        nb = ((nb_str[k] - '0') * my_compute_power_rec(10, l - 1)) + nb;
        l--;
    }
    if (minus_detector(str) == 1)
        nb = nb * -1;
    res = check_integer(str, nb);
    return res;
}
