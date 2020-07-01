/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** include for mysh2
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "lib.h"
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

#ifndef MYSH_
#define MYSH_

# define END 0
# define BUFF_SIZE	10000

typedef struct minishell_t
{
    char **arg;
    char *buffer;
    pid_t pid;
    int fd;
    int check;
    int g;
} mysh_s;

typedef struct stat	t_stat;
typedef struct path_s
{
    char *path;
    int	len;
    struct path_s *next;
} struct_t;

typedef struct shell_s
{
    char *name;
    void (*func)(char **, char *, char **);
} shell_t;

void ctrl_c(int i);
void init_mysh(mysh_s *mysh);
int handle_errors(char *buffer, mysh_s mysh, char **env, char **envp);
void my_exit(char **arg);
int my_cd(char *buffer, char **arg, char **env, int i);
void free_tab(char **tab);
int my_pid(char **env, mysh_s *mysh, int i, char **arg);
int my_separator(mysh_s *mysh, char **env, int i, char *str);
int main_mysh(mysh_s mysh, char **env, char **envp);
int my_redirect_right(mysh_s *mysh, char **env, char *str);
char **my_get_env(char **env);
int second_main_mysh(mysh_s *mysh, char **env, char *str);
int nb_words(char *str);
int nb_wordnocolumn(char *str);
int nb_wordyo(char *str);
int recoded_env(char **envp, char *line, char **arguments);
int setenv_two_arg(char **envp, char *line, char **arguments, int checker);
int cat_to_env_no_a(char **envp, char **arguments, int checker, int last_env);
void setenv_three_arg(char **envp, char *line, char **arguments, int checker);
void cat_to_env(char **envp, char **arguments, int checker, int last_env);
void error_env(char *line);
void my_unsetenv(char **envp, char *line, char **arguments);
int print_env(char **envp, char *line, char *newline);
int is_it_alpha(char *str);
int my_strcmp_equal(char *s1, char *s2);
void ant_cd(char *line, char **envp);
void signal_handler(int status);
char **delimit_string(char *src, const char *delim);
int	parsing_input(char *input, struct_t *list, char **g_envv);
int my_free(char **arr);
int separator(char c, char *sep);
char *get_new_cmd(char *cmd, char *cmdref, int start, int end);
void skip_word(char *cmd, int *i);
char *check_redir(char *input);
int	my_execution(char *input, struct_t **list, char ***g_envv);
int	my_pipe(char *input, struct_t **list, char ***g_envv);
struct_t *get_path(char **envp);
int	my_strncmp(const char *s1, const char *s2, int n);
int my_echo(mysh_s mysh, char **env);
int count_arg(mysh_s mysh);
int find_arg(mysh_s mysh);
int find_echo(mysh_s mysh);
int switch_echo(mysh_s mysh, int feco, int c, int count_argc);
char  *echo_e(mysh_s mysh, int feco);
char *echo_c(mysh_s mysh, int feco);
char *check_str(mysh_s mysh);
char *combine_str(mysh_s mysh, int feco);
char check_arg(char *str);
void print_arg(mysh_s mysh);
char *my_strncpy(char *dst, const char *src, size_t len);
int	my_builtins(char *buf, char ***g_envv);
int	my_parsing(char *input, struct_t **list, char ***g_envv,
mysh_s *mysh);
int	free_path(struct_t *list, int is_child);
int seg_and_divzero(pid_t pid, int *storage);
int redir_double_input(char *file);
int ambiguousoutoutput(char **cmd_pipe, char *input, int h_pipe);
int nullcommand(char *input, int pipe, int h_pipe, int space);
int check_for_chev(char *input, int re_l, int re_r);
void error_disp_cd(char *path);
char *get_user(char **envp);
void normal_cd(char *line, char *buffer, char **oldwd, int *chinese);
void end_env(char **envp, int m, char **arg);
void my_print_env(char **envp, int i);
void end_main(char *str);

#endif /* MYSH_ */
