#include "main.h"

/**
*main - main shell function
*
*Return - 1 on error 0 on success
*/

int main(void)
{
	char *cmd;
	char **args;
	int status;
	pid_t pid;
	extern char **environ;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
		{
			printf(PROMPT);
			fflush(stdout);
		}
		cmd = read_line();

		if (cmd == NULL || feof(stdin))
		{
			if (is_interactive)
			{
				printf("\n");
			}
			exit(cmd == NULL ? EXIT_FAILURE : EXIT_SUCCESS);
		}
		args = split_line(cmd);
		pid = fork();

		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}
		else
		{
			perror("fork");
		}
		free(cmd);
		free(args);
	}
	return (EXIT_SUCCESS);
}
