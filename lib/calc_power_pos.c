/*
** EPITECH PROJECT, 2023
** calc power
** File description:
** return the value with the power
*/

unsigned long int calc_power_pos(int nb, int p)
{
    int count = p;
    unsigned long int raised = 1;

    if (p == 0){
        return 1;
    }
    if (p < 0){
        return 0;
    }
    while (count > 0){
        raised = raised * nb;
        count = count - 1;
            }
    return raised;
}
