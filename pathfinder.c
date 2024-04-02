#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 256


char *env_pathfinder(char **cmd) {
    char *path = getenv("PATH");

    if (strncmp(cmd[0], "./", 2) == 0 || cmd[0][0] == '/' || strncmp(cmd[0], "../", 3) == 0) {
        if (access(cmd[0], F_OK) == 0) {
            return strdup(cmd[0]);
        }
    }

    if (!path) {
        return NULL;
    }

    return NULL;
}

