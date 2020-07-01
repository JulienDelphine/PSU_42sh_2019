/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** check if two string are identical
*/

#include <unistd.h>
#include <stdio.h>

int my_strcmp(char *check, char *str)
{
    int i = 0;

    if (str == NULL)
        return (84);
    while ((str[i] == check[i]) && (check[i] != '\0') && (str[i] != '\0'))
        i++;
    return (check[i] - str[i]);
}