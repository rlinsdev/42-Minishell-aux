/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-mini-shell2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:34 by rlins             #+#    #+#             */
/*   Updated: 2022/11/10 13:59:42 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/making-linux-shell-c/
#include <minishell.h>

#define MAXCOM 1000 // max number of commands to be supported
#define MAXLIST 100 // max number of letters to be supported

// Clearing the shell using escape sequences
#define clear() printf("\033[H\033[J")

static void init_shell();
static void printDir();


void mini_mini_shell2()
{
	char inputString[MAXCOM];
	char *parsedArgs[MAXLIST];
	int execFlag = 0;

	init_shell();

	while (1)
	{
		printDir();

		exit(EXIT_SUCCESS);
	}

}

/**
 * @brief Print current directory
 *
 */
static void printDir()
{
	// Current work directory
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

/**
 * @brief Greeting shell in initialization
 */
static void init_shell()
{
	clear();
	printf("\n\n\n\n******************************************");
	printf("\n\n\n\t****MY SHELL****");
	printf("\n\n\t-USE AT YOUR OWN RISK-");
	printf("\n\n\n\n******************************************");
	char *user_name = getenv("USER");
	printf("\n\n\nUSER is: @%s", user_name);
	printf("\n");
	sleep(1);
	clear();
}
