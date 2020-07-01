/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** str to word array with charac for separation of arg
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int my_strl(char *str, char charac, int i)
{
    int j = 0;

    while ((str[i] != '\0') && (str[i] != '\n') && (str[i] != charac)) {
        i++;
        j++;
    }
    return (j);
}

int countword(char *buffer, char charac)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        if ((buffer[i] == charac && buffer[i + 1] != '\0')
        || (buffer[i] == '\t' && buffer[i + 1] != '\0'))
            j++;
        i++;
    }
    j++;
    return (j);
}

int move_char(char *buffer, int i, char charac)
{
    for (;buffer[i] == charac || buffer[i] == '\t'; i++);
    return (i);
}

char **my_str_to_word_array(char *buffer, char charac, int j, int k)
{
    char **array = malloc(sizeof(char *) * ((countword(buffer, charac) + 1)));
    if (array == NULL)
        exit(84);
    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0';) {
        if (buffer[i] == charac || buffer[i] == '\n'|| buffer[i] == '\t') {
            i = move_char(buffer, i, charac);
        j++;
        k = 0;
        }
        array[j] = malloc(sizeof(char) * ((my_strl(buffer, charac, i) + 1)));
        if (array[j] == NULL)
            exit(84);
        for ( ;(buffer[i] != '\0') && (buffer[i] != '\n')
        && (buffer[i] != charac) && buffer[i] != '\t'; k++, i++) {
            array[j][k] = buffer[i];
        }
        array[j][k] = '\0';
    }
    array[j + 1] = NULL;
    return (array);
}