/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:53:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 15:53:05 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>


int	start(int argc, char **argv, char **envp)
{
	aux_printf();
	char *str = aux_malloc();
	aux_free(str);
	aux_write();
	aux_write2(1, "U-hull!\n", 8);
	aux_open();
	aux_read();
	aux_access("/home/rlins/.asdf/shims/tr");
	aux_access("/usr/bin/tr");
	aux_execve(envp, "/usr/bin/ls");


	return (0);
}
