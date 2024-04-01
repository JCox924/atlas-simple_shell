#include "main.h"

/**
*main - main shell function
*
*Return - 1 on error 0 on success
*/

int main(void)
{
	char *cmd;
	char *newline;
	char *argv[2];
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

		if (!fgets(cmd, MAX_INPUT, stdin))
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("fgets");
				continue;
			}
		}
		newline = strchr(cmd, '\n');
		
		if (newline)
		{
			*newline = '\0';
		}
		if (strlen(cmd) == 0)
		{
			continue;
		}
		argv[0] = cmd;
		argv[1] = NULL;
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			continue;
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);

			if (execve(cmd, argv, environ) == -1)
			{
				fprintf(stderr, "%s: Command not found\n", cmd);
				exit(EXIT_FAILURE);
			}
		}
		return (EXIT_SUCCESS);
	}
}
