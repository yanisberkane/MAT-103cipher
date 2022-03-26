/*
** EPITECH PROJECT, 2021
** put_base_nbr
** File description:
** Displays the base conversion of an int
*/

void my_putchar(char c);

int put_base_nbr(unsigned int nb, unsigned int base);

char conv_dec_to_hex(int res)
{
    switch (res) {
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
    return 0;
}

int put_high_base_nbr(unsigned int nb, unsigned int base)
{
    int div;
    int mod;

    div = nb / base;
    put_base_nbr(div, base);
    mod = nb % base;
    put_base_nbr(mod, base);
    return 0;
}

int put_base_nbr(unsigned int nb, unsigned int base)
{
    int neg;

    if (nb < base) {
        if (nb > 9) {
            my_putchar(conv_dec_to_hex(nb));
            return 0;
        }
        my_putchar(nb + '0');
        return 0;
    } else {
        put_high_base_nbr(nb, base);
        return 0;
    }
    return 0;
}