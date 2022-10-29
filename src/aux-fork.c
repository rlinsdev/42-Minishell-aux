/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:14:02 by rlins             #+#    #+#             */
/*   Updated: 2022/10/29 10:44:45 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	aux_fork()
{
	int pid = fork();

	// Error when fork
	if (pid == -1)
		printf("Erro when forking\n");

	if(pid == 0)
	{
		printf("This is the Child process: %d\n", pid);
		// calling ping to test the child and keep going with parent
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	else
	{
		// Wait will be called here. If not, the prompt will be release before
		// finish the child process...
		wait(NULL);
		printf("This is the main/Parent process: %d\n", pid);
	}
}

void	aux_fork2()
{
	int	id = fork ();

	int proc = 0;

	// Child?
	if (id == 0)
		proc = 1;
	else
		proc = 10;

	// Wait ALL the childs, and then, execute parent process
	if (!id == 0) 
		sleep(1);

	for (int i = proc; i < proc + 9; i++)
	{
		printf("%d ", i);
	}
	if (id != 0)
		printf("\n");
}
