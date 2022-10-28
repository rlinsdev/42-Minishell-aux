/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:18:46 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 15:55:30 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void aux_execve(char **envp, char *cmd)
{
	// Code to check all the envp variables.
	// int j = 0;
	// while (envp[j]!= NULL)
	// {
	// 	printf("envp[%d]: %s\n", j, envp[j]);
	// 	j++;
	// }


	char *options[3] = {"ls", "-la", NULL};

	printf("\nBegin: Exec-Ve:\n");

	execve(cmd, options, envp);
	// Any thing after execve, does not execute
}
