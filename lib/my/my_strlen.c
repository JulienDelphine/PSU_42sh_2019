/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}