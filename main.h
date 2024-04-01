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
char* read_line(void);
char** split_line(char *line, const char *delimiters);

#endif
