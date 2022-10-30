/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-sigaction2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:21:08 by rlins             #+#    #+#             */
/*   Updated: 2022/10/30 16:40:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void handler_sigtstp(int sig)
{
	// Ctrl + Z will call this
	printf("Stop not allowed\n");
}

// Ctrl +Z Now will stop. Fg will come back the program
void handler_sigcont(int sig)
{
	printf("Input number:");
	fflush(stdout);
}

int	aux_sigaction2()
{
	struct sigaction sa;
	sa.sa_handler = &handler_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);

	// signal(SIGTSTP, &handler_sigtstp);


	int x;
	printf("input a number: ");
	scanf("%d", &x);
	printf("The result %d *5 is: %d\n", x, x * 5);

	return (0);
}
