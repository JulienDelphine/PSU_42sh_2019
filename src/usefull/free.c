/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** all free function
*/

#include "../include/mysh.h"

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
}