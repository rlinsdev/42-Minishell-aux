/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:57:15 by rlins             #+#    #+#             */
/*   Updated: 2022/10/29 11:01:37 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int aux_pipe()
{
	// Array of integer. 2 File Descriptors
	int fd[2];

	// "bytes written in PIPEDeS[1] can be read by PIPEDeS[0]"
	if (pipe(fd) == -1)
	{
		printf("Error on try to generate Pipe\n");
		return (1);
	}

	int pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error to generate Fork(1)\n");
		return (1);
	}

	// Child process 1 (Ping)
	if (pid1 == 0)
	{
		// Get the child execution, and apply the ping cmd
		// Change the Stander output.
		// Duplicate FD1 to FD2
		dup2(fd[1], STDOUT_FILENO);

		close(fd[0]); // I don use
		close(fd[1]); // Remains open, when duplicated
		// Execution
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}

	int pid2 = fork();

	if (pid2 == -1)
	{
		printf("Error to generate Fork(2)\n");
		return (2);
	}

	// Second Child
	if (pid2 == 0)
	{
		// Duplicate FileDescriptor, change output
		dup2(fd[0], STDIN_FILENO); // Standard Input

		close(fd[0]);
		close(fd[1]);

		execlp("grep", "grep", "rtt", NULL);
	}

	close(fd[0]);
	close(fd[1]);

	// Wait the execution of child process (ping)
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
