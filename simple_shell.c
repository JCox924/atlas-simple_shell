#include "main.h"

/**
*main - main shell function
*
*Return - 1 on error 0 on success
*/

int main(void)
{
	char cmd[MAX_INPUT];
	char *newline;
	char *argc[2];
	int status;
	pid_t pid;

	while (1)
	{
		printf(PROMPT);
		fflush(stdout);

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
		else if (pid == 0)
		{
			if (execve(cmd, argv, NULL) == -1)
			{
				fprintf(stderr, "%s: Command nor found\n", cmd);
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		return (EXIT_SUCCESS);
	}
}
