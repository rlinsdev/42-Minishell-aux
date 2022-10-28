/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:37:30 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 15:01:36 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

int	aux_access(char *path_cmd)
{
	int result;
	result = access(path_cmd, 0);

	if (result == 0)
		printf("path: %s is accessible to apply the cmd\n", path_cmd);
	else
		printf("Access Deny to apply the cmd: %s\n", path_cmd);
	return (result);
}
