/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** Main for mysh2
*/

#include "mysh.h"

int	free_path(struct_t *list, int is_child)
{
    struct_t *tmp;
    struct_t *tmp2;

    tmp = list;
    while (tmp) {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
    if (!is_child) {
        printf("\n");
        exit (0);
    }
    return (0);
}

int check_ret(char *str, struct_t *list, char **envp, mysh_s mysh)
{
    if (my_parsing(str, &list, &envp, &mysh) == -1)
        return (free_path(list, 1));
    return (1);
}

int check_list(int ret, struct_t *list)
{
    if (ret == 0) {
        if (isatty(STDIN_FILENO) != 0)
            printf("exit");
        return (free_path(list, 0));
    }
    return (1);
}

int main_mysh(mysh_s mysh, char **env, char **envp)
{
    char *str = NULL;
    struct_t *list;
    int ret = 0;
    char buffer[BUFF_SIZE + 1];

    list = get_path(envp);
    signal(SIGINT, ctrl_c);
    while (1) {
        if ((ret = read(0, buffer, BUFF_SIZE)) <= 0)
            check_list(ret, list);
        else
            buffer[ret - 1] = 0;
        handle_errors(buffer, mysh, env, envp);
        str = clean_str(buffer);
        mysh.arg = my_str_to_word_array(str, 32, 0, 0);
        if (1 && ret > 1) {
            check_ret(str, list, envp, mysh);
        }
        end_main(str);
    }
}

int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    static char **my_env;
    mysh_s mysh;

    init_mysh(&mysh);
    my_env = malloc(1000);
    if (my_env == NULL)
        return (84);
    for (int j = 0; envp[j] != NULL; j++)
        my_env[j] = envp[j];
    if (isatty(STDIN_FILENO) != 0)
        my_printf("$> ");
    main_mysh(mysh, my_env, envp);
    return (0);
}
