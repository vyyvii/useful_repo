/*
** EPITECH PROJECT, 2026
** cuddle
** File description:
** Recode pandas library
*/

#include "utilslib.h"

char **copie_heads(dataframe_t *df)
{
    char **column_names = malloc(sizeof(char *) * (df->nb_columns + 1));

    if (!column_names)
        return NULL;
    for (int i = 0; i < df->nb_columns; i++) {
        column_names[i] = strdup(df->column_names[i]);
        if (!column_names) {
            free_partial_table((void **)column_names, i);
            return NULL;
        }
    }
    column_names[df->nb_columns] = NULL;
    return column_names;
}

void free_csv(char ***data)
{
    if (!data)
        return;
    for (int i = 0; data[i]; i++) {
        for (int j = 0; data[i][j]; j++)
            free(data[i][j]);
        free(data[i]);
    }
    free(data);
}

void free_partial_csv(char ***data, int n)
{
    if (!data)
        return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; data[i][j]; j++)
            free(data[i][j]);
        free(data[i]);
    }
    free(data);
}
