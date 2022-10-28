/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:22:01 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 11:35:24 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	aux_write()
{
	write(1, "x\n", 2);
}

int	aux_write2(int fd, const void *buf, size_t nbytes)
{
	return (write(fd, buf, nbytes));
}
