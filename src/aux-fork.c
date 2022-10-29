/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:14:02 by rlins             #+#    #+#             */
/*   Updated: 2022/10/29 08:30:37 by rlins            ###   ########.fr       */
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
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	else
	{
		// Wait will be called here. If not, the prompt will be release before
		// finish the child process...
		wait(NULL);
		printf("This is the main/Parent process: %d\n", pid);
	}
}
