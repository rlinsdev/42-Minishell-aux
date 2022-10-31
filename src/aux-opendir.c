/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-opendir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:12:00 by rlins             #+#    #+#             */
/*   Updated: 2022/10/31 11:44:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	aux_opendir()
{
	DIR *dir;
	struct dirent *sd;

	dir = opendir(".");

	if (dir == NULL)
	{
		printf("Error!\n");
		exit(1);
	}

	while ((sd = readdir(dir)) != NULL)
	{
		printf(">> %s\n", sd->d_name);
	}

	closedir(dir);
}
