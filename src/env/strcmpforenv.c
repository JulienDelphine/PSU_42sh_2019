/*
** EPITECH PROJECT, 2020
** check_and_cat.c
** File description:
** check and cat
*/

#include "../include/mysh.h"

int my_strcmp_equal(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '=' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (-1);
        i++;
    }
    return (0);
}
