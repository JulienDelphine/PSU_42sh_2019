/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** Main for mysh2
*/

#include "../include/mysh.h"

struct_t *new_path(char *path, int len)
{
    struct_t *new;

    new = malloc(sizeof(struct_t));
    if (new == NULL)
        return (NULL);
    new->path = path;
    new->len = len;
    new->next = NULL;
    return (new);
}

void add_path(struct_t **list, char *path, int len)
{
    struct_t *new;
    struct_t *tmp;

    new = new_path(path, len);
    if (!*list)
        *list = new;
    else {
        tmp = *list;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void parsing_env(char *path_line, struct_t **list)
{
    int	start = 5;
    int	end = 4;

    while (path_line[++end]) {
        if (path_line[end] == ':') {
            add_path(list, path_line + start, end - start);
            start = end + 1;
        }
    }
    if (start != end)
        add_path(list, path_line + start, end - start);
}

struct_t *get_path(char **envp)
{
    int	i = -1;
    struct_t *list = NULL;

    while (envp[++i]) {
        if (!my_strncmp(envp[i], "PATH=", 5))
            parsing_env(envp[i], &list);
    }
    return (list);
}