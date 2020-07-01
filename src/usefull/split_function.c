/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** split
*/

#include "../include/mysh.h"

static void clear_str(char *str, const char c, char const *end_ptr)
{
    while (str < end_ptr) {
        str = my_strchrnul(str, c);
        *str++ = '\0';
    }
}

static char *skip_blanks(char *str, char const *end_ptr)
{
    while (!*str && str < end_ptr)
        str++;
    return (str);
}

static int count_word_nb(char *str, char const *end_ptr)
{
    int nb_count = 0;

    str = skip_blanks(str, end_ptr);
    while (str < end_ptr) {
        if (*str)
            nb_count++;
        while (*str)
            str++;
        str = skip_blanks(str, end_ptr);
    }
    return (nb_count);
}

static int word_array(char **array, char *str, char const *end_ptr)
{
    while (str < end_ptr) {
        *array = my_strdup(str);
        if (*array == NULL)
            return (0);
        while (*str)
            str++;
        str = skip_blanks(str, end_ptr);
        array++;
    }
    *array = NULL;
    return (1);
}

char **delimit_string(char *src, const char *delim)
{
    char **array;
    char const *end_ptr;
    char *str = my_strdup(src);

    if (!str)
        return (NULL);
    end_ptr = str + my_strlen(str);
    while (*delim)
        clear_str(str, *delim++, end_ptr);
    array = malloc(sizeof(char *) * (count_word_nb(str, end_ptr) + 1));
    if (!array)
        return (NULL);
    if (word_array(array, skip_blanks(str, end_ptr), end_ptr) == 0)
        return (NULL);
    free(str);
    return (array);
}