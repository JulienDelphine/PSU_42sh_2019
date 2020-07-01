/*
** EPITECH PROJECT, 2020
** count_words.c
** File description:
** count words
*/

#include "../include/mysh.h"

int nb_wordyo(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        if ((str[i] == ' ' && str[i + 1] != '\0' &&
        str[i + 1] != '|') || str[i] == ':')
            nb++;
        i++;
    }
    nb++;
    return (nb);
}

int nb_wordnocolumn(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        if ((str[i] == ' ' && str[i + 1] != '\0' && str[i + 1] != '|'))
            nb++;
        i++;
        if (str[i] == ';') {
            nb--;
            break;
        }
    }
    nb++;
    return (nb);
}

int nb_words(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        if ((str[i] == ' ' && str[i + 1] != '\0') || str[i] == ':')
            nb++;
        i++;
    }
    nb++;
    return (nb);
}

