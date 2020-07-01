/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** parsing
*/

#include "../include/mysh.h"

int check_command(char **command)
{
    if (command == NULL)
        return (-1);
    for (int i = 0; command[i] != NULL; i++){
        command[i] = clean_str(command[i]);
    }
    return (0);
}

int	my_parsing(char *input, struct_t **list, char ***g_env, mysh_s *mysh)
{
    int	i = -1;
    char **command;
    char **new_arg = malloc(sizeof(char *) * 10);
    int no = 1;

    command = delimit_string(input, ";");
    check_command(command);
    while (command[++i]) {
        if (my_strncmp(command[i], "echo", 4) == 0){
            no = 0;
            my_echo(*mysh, g_env[0]);
        }
        new_arg = delimit_string(command[i], " ");
        if (recoded_env(g_env[0], command[i], new_arg) != 1 && no == 1)
            if (my_pipe(command[i], list, g_env) == -1)
                return (my_free(command));
        no = 1;
    }
    my_free(command);
    return (0);
}

char *concat_path(struct_t *s1, char *s2)
{
    int	i = 0;
    int	j = -1;
    char *new_str;

    new_str = malloc(sizeof(char *) * (s1->len + my_strlen(s2) + 2));
    if (!s2 || new_str == NULL)
        return (NULL);
    while (s1->path && i < s1->len) {
        new_str[i] = s1->path[i];
        ++i;
    }
    new_str[i++] = '/';
    while (s2 && s2[++j])
        new_str[i + j] = s2[j];
    new_str[i + j] = 0;
    return (new_str);
}

void input_conditions(char **tab)
{
    if (opendir(tab[0]) != NULL) {
        printf("%s: Permission denied.\n", tab[0]);
        exit(0);
    }
    if (strcmp("cd", tab[0]) != 0 && strcmp("env", tab[0]) != 0 &&
    strcmp("setenv", tab[0]) != 0 && strcmp("unsetenv", tab[0]) != 0 &&
    strcmp("exit", tab[0]) != 0){
        printf("%s", tab[0]);
        printf(": Command not found.\n");
    }
}

int	parsing_input(char *input, struct_t *list, char **g_envv)
{
    struct_t *tmp;
    t_stat st;
    char *parsing_input;
    char **tab;
    int	execution;

    if ((tab = delimit_string(input, " \t")) == NULL)
        return (-1);
    execution = (execve(tab[0], tab, g_envv) != -1 ? 1 : 0);
    tmp = list;
    while (tmp && !execution && strcmp("cd", tab[0]) != 0) {
        parsing_input = concat_path(tmp, tab[0]);
        if (lstat(parsing_input, &st) != -1)
            execve(parsing_input, tab, g_envv);
        free(parsing_input);
        tmp = tmp->next;
    }
    input_conditions(tab);
    exit (0);
    return (my_free(tab));
}
