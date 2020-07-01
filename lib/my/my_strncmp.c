/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** my_strncmp
*/

int	my_strncmp(const char *s1, const char *s2, int n)
{
    char *str1;
    char *str2;

    str1 = (char *)s1;
    str2 = (char *)s2;
    while (*str1 == *str2 && *str1 && n--) {
        ++str1;
        ++str2;
    }
    if (!n)
        return (0);
    return (*str1 - *str2);
}