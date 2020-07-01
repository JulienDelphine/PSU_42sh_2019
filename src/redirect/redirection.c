/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** redirection
*/

#include "../include/mysh.h"

char *get_file_name(char *file, int end)
{
    int	i = 0;
    int	j = 0;
    char *new_file;

    new_file = malloc(sizeof(char) * (end - i + 1));
    while (file[i] && separator(file[i], "<> \t"))
        ++i;
    if (new_file == NULL)
        return (NULL);
    new_file[end - i] = 0;
    while (file[i] && !separator(file[i], "<> \t"))
        new_file[j++] = file[i++];
    return (new_file);
}

int	my_output_redir(char *file, int end)
{
    char *new_file;
    int	out;
    int	redir_out;

    new_file = get_file_name(file, end);
    redir_out = (file[1] == '>' ? 0 : O_TRUNC);
    if (new_file == NULL)
        return (printf("Error\n"));
    out = open(new_file, O_WRONLY | redir_out | O_APPEND | O_CREAT, 0644);
    if (out == -1) {
        printf("%s", new_file);
        free(new_file);
        return (printf(": Permission denied\n"));
    }
    dup2(out, 1);
    close(out);
    free(new_file);
    return (0);
}

int	my_input_redir(char *file, int end)
{
    char *new_file;
    int	in;

    new_file = get_file_name(file, end);
    if (new_file == NULL)
        return (printf("Error\n"));
    if (file[1] == '<')
        return (redir_double_input(new_file));
    in = open(new_file, O_RDONLY);
    if (in == -1) {
        printf("%s", new_file);
        free(new_file);
        return (printf(": Permission denied\n"));
    }
    dup2(in, 0);
    close(in);
    free(new_file);
    return (0);
}

char *check_redir(char *input)
{
    int i = 0;
    int	start = -1;
    int	end = -1;
    char *new_cmd = input;
    while (input[i]) {
        if (input[i] == '>' || input[i] == '<') {
            start = i;
            skip_word(input, &i);
            end = i;
            if ((input[start] == '>' &&
                my_output_redir(input + start, end - start)) ||
                (input[start] == '<' &&
                my_input_redir(input + start, end - start)) ||
                !(new_cmd = get_new_cmd(new_cmd, input, start, end)))
                return (NULL);
        }
        if (input[i])
            ++i;
    }
    return (new_cmd);
}
