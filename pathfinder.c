#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 256

void free_array(char **array) {
    int i;
    if (array == NULL)
        return;
    
    for (i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }
    free(array);
}

char *env_pathfinder(char **cmd) {
    char *path = getenv("PATH");

    if (path == NULL) {
        return NULL;
    }

    if (strncmp(cmd[0], "./", 2) == 0 || cmd[0][0] == '/' || strncmp(cmd[0], "../", 3) == 0) {
        if (access(cmd[0], F_OK) == 0) {
            return strdup(cmd[0]);
        }
    }

    return (NULL);
}
