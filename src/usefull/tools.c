/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** tools
*/

#include "../include/mysh.h"

int separator(char c, char *sep)
{
    int i = -1;

    while (sep[++i]) {
        if (c == sep[i])
            return (1);
    }
    return (0);
}

char *get_new_cmd(char *cmd, char *cmdref, int start, int end)
{
    int	i = -1;
    int	j;
    char *new_cmd;

    new_cmd = malloc(sizeof(char) * (my_strlen(cmd) - (end - start) + 1));
    if (new_cmd == NULL)
        return (NULL);
    while (cmd[++i] && !separator(cmd[i], "<>"))
        new_cmd[i] = cmd[i];
    j = i + end - start;
    while (cmd[j])
        new_cmd[i++] = cmd[j++];
    new_cmd[i] = 0;
    if (cmd != cmdref)
        free(cmd);
    return (new_cmd);
}

void skip_word(char *cmd, int *i)
{
    while (cmd[*i] && separator(cmd[*i], "<> \t"))
        ++(*i);
    while (cmd[*i] && !separator(cmd[*i], "<> \t"))
        ++(*i);
}

int my_free(char **arr)
{
    int i = -1;

    if (!arr)
        return (1);
    while (arr[++i]) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return (0);
}

char *my_strncpy(char *dst, const char *src, size_t len)
{
    size_t i;

    i = -1;
    while (++i < len)
        if (*(src + i))
            *(dst + i) = *(src + i);
        else {
            while (i < len)
                *(dst + i++) = '\0';
        }
    return (dst);
}