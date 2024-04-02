#include "main.h"

/**
*env_pathfinder - returns path to native commands (fun_fact: pathfinder is one of the toughest Army schools)
*
*
*Return: path for command inputted
*/

char env_pathfinder(void)
{
	int pos = 0;
	char *path = get_env("PATH");
	char **path_az, *tgt;

	if (strncmp(cmd[0], "./", 2) == 0 || cmd[0][0] == "/" || strncmp(cmd[0], "../". 3))
	{
		if (access(cmd[0], F_OK) == 0)
		{
			return (strdup(cmd[0]);
		}
	}

	if (!path)
	{
		return (NULL);
	}
	path_az = container(path, ':');

	for (;path_dir[pos]; pos++)
	{
		tgt = malloc(MAX_INPUT);
		strcpy(tgt, path_dir[i]);
		strcat(tgt, "/");
		strcat(tgt, cmd[0]);

		if (access(tgt, F_OK) == 0)
		{
			free_array(path_az);
			return (tgt);
		}
		free(tgt);
	}
	free_array(path_az);
	return (NULL);
}
