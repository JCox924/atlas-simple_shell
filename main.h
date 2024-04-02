#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define PROMPT "> "
#define DELIMITERS " \n"
#define STDIN_CONCAT(c) (fwrite(STDOUT_FILENO, c, _strlen(c)))

char* read_line(void);
char** split_line(char *line);
char env_pathfinder(void);
char **container(char *str, char dlim);

#endif
