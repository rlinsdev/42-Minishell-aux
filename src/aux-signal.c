/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:33:55 by rlins             #+#    #+#             */
/*   Updated: 2022/10/29 15:10:41 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://linuxhint.com/signal_handlers_c_programming_language/

#include <minishell.h>

//Ctr+C -> Get inside
static void	sig_handler(int signum)
{
	printf("Inside handler func\n");
	signal(SIGINT,SIG_DFL);
}

// Ctrl + \ -> Will stop the process
void	aux_signal()
{
	while  (1)
	{
		printf("Inside main function\n");
		signal(SIGINT, sig_handler);
		sleep(1);
	}
}

void	aux_signal2()
{
	pid_t pid;

	signal(SIGUSR1, sig_handler);
	printf("Inside main function\n");
	pid = getpid();
	kill(pid, SIGUSR1);
	printf("Inside main function\n");
}

static void sig_handler_parent(int signum)
{
	printf("Parent : Received a response signal from child \n");
}

static void sig_handler_child(int signum)
{
	printf("Child : Received a signal from parent \n");
	sleep(1);
	kill(getppid(),SIGUSR1);
}
void	aux_signal3()
{
	pid_t pid;
	if ((pid = fork())<0)
	{
		printf("Fork Failed\n");
		exit(1);
	}
	/* Child Process */
	else if (pid==0)
	{
		signal(SIGUSR1, sig_handler_child); // Register signal handler
		printf("Child: waiting for signal\n");
		pause();
	}
	/* Parent Process */
	else
	{
		signal(SIGUSR1, sig_handler_parent); // Register signal handler
		sleep(1);
		printf("Parent: sending signal to Child\n");
		kill(pid, SIGUSR1);
		printf("Parent: waiting for response\n");
		pause();
	}
}
