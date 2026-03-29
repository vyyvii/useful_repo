/*
** EPITECH PROJECT, 2026
** cuddle
** File description:
** Recode pandas library
*/

#include "utilslib.h"

static void print_separator(dataframe_t *df, int x, int fd)
{
    if (x < df->nb_columns - 1)
        write(fd, df->separator, strlen(df->separator));
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    int fd = (dataframe && filename)
        ? open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644) : -1;

    if (fd == -1)
        return FAILURE;
    for (int i = 0; dataframe->column_names[i]; i++) {
        write(fd, dataframe->column_names[i],
            strlen(dataframe->column_names[i]));
        print_separator(dataframe, i, fd);
    }
    write(fd, "\n", 1);
    for (int i = 0; dataframe->data[i]; i++) {
        for (int j = 0; dataframe->data[i][j]; j++) {
            write(fd, dataframe->data[i][j], strlen(dataframe->data[i][j]));
            print_separator(dataframe, j, fd);
        }
        write(fd, "\n", 1);
    }
    close(fd);
    return SUCCESS;
}
