/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:53:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 12:58:06 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>


int	start(int argc, char **argv)
{
	aux_printf();
	char *str = aux_malloc();
	aux_free(str);
	aux_write();
	aux_write2(1, "U-hull!", 7);
	aux_open();


	return (0);
}
