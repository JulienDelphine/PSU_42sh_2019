/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** cut str
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

char *my_str_separator(char *str)
{
    char *new_str = NULL;
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    for (; str[i] != ';'; i++);
    i++;
    k = i;
    for (; str[i] != '\0'; i++, j++);
    new_str = malloc(sizeof(char) * j + 1);
    for (; k != i; k++, m++)
        new_str[m] = str[k];
    new_str[m] = '\0';
    new_str = clean_str(new_str);
    return (new_str);
}

int strlen_cut(char *arg, char charac)
{
    int i = 0;

    while (arg[i] != charac)
        i++;
    return (i);
}

char *my_strcut(char *arg, char charac)
{
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * strlen_cut(arg, charac) + 1);

    if (strlen_cut(arg, charac) == 0)
        return (NULL);
    for (; arg[j] != charac; j++);
    for (; arg[j] == ' '; j--);
    for (; k != j; k++)
        str[k] = arg[k];
    str[k] = '\0';
    str = clean_str(str);
    return (str);
}