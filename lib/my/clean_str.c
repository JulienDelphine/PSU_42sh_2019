/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** clean str
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int count_correct_chars(char *str)
{
    int j = 0;
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if ((str[i] != ' ' && str[i] != '\t')
        || ((str[i] == ' ' || str[i] == '\t') && count == 1
        && str[i + 1] != ' ' && str[i + 1] != '\t'
        && str[i + 1] != 0)) {
            count = 1;
            j++;
        }
    }
    return (j);
}

void fill_clean_str(char *str, char *new_str)
{
    int j = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t'){
            new_str[j++] = str[i];
            count = 1;
        }
        if ((str[i] == ' ' || str[i] == '\t') && count == 1){
            new_str[j++] = str[i];
            count = 0;
        }
    }
    if (new_str[j - 1] == ' ' || new_str[j - 1] == '\t')
        new_str[j - 1 ] = '\0';
    else
        new_str[j] = '\0';
}

char *clean_str(char *str)
{
    char *new_str = NULL;

    if (str == NULL)
        return (NULL);
    if (str[0] == '\n')
        return (str);
    new_str = malloc(sizeof(char) * count_correct_chars(str) + 1);
    fill_clean_str(str, new_str);
    new_str[strlen(new_str)] = '\0';
    return (new_str);
}
