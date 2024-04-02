#include "main.h"

void free_array(char **array);

char *env_pathfinder(char **cmd) {
    int pos = 0;
    char *path = getenv("PATH");
    char **path_az, *tgt;

    if (path == NULL) {
        return NULL;
    }

    if (strncmp(cmd[0], "./", 2) == 0 || cmd[0][0] == '/' || strncmp(cmd[0], "../", 3) == 0) {
        if (access(cmd[0], F_OK) == 0) {
            return strdup(cmd[0]);
        }
    }

    path_az = container(path, ':');

    for (; path_az[pos]; pos++) {
        tgt = malloc(MAX_INPUT);
        if (tgt == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        strcpy(tgt, path_az[pos]);
        strcat(tgt, "/");
        strcat(tgt, cmd[0]);

        if (access(tgt, F_OK) == 0) {
            free_array(path_az);
            return tgt;
        }
        free(tgt);
    }

    free_array(path_az);
    return NULL;
}

void free_array(char **array) {
    int i;
    if (array == NULL)
        return;
    
    for (i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }
    free(array);
}

