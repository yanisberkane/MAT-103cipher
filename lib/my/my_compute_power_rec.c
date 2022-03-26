/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** Returns power of a num
*/

int my_compute_power_rec(int nb, int p)
{
    int Puiss;

    Puiss = nb;
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    Puiss = Puiss * my_compute_power_rec(nb, p - 1);
    return Puiss;
}
