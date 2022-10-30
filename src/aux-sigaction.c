/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-sigaction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:21:08 by rlins             #+#    #+#             */
/*   Updated: 2022/10/30 15:38:02 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int x = 0;

void handle_sigusr1(int sig)
{
	if (x == 0)
		printf("\n(HINT) Remember that bla bla bla\n");
}

int	aux_sigaction()
{
	int pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);

	} else {
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);


		printf("What is the result of 3 x 5?");
		scanf("%d", &x);
		if (x == 15)
			printf("Right!\n");
		else
			printf("Wrong!\n");

		wait(NULL);
	}
	return (0);
}
