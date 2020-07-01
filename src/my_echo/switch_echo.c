/*
** EPITECH PROJECT, 2020
** my_echo
** File description:
** switch_eco
*/

#include "mysh.h"

int switch_echo(mysh_s mysh, int feco, int c, int count_argc)
{
    switch (mysh.arg[count_argc][mysh.g]) {
    case 'E':
        print_arg(mysh);
        break;
    case 'n':
        if (mysh.arg[count_argc][mysh.g - 1] != 69
        && mysh.arg[count_argc][mysh.g + 1] != 69 &&
        mysh.arg[count_argc + 1][mysh.g + 1] != 0) {
            mysh.arg[feco + 2] = combine_str(mysh, feco);
            mysh.arg[feco] = echo_e(mysh, feco + 2);
        }
        c++;
        break;
    }
    return c;
}
