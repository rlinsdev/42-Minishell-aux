/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:53:43 by rlins             #+#    #+#             */
/*   Updated: 2022/10/28 11:34:46 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>


int	start(int argc, char **argv)
{
	aux_printf();
	char *str = aux_malloc();
	aux_free(str);
	aux_write();
	aux_write2(1, "Uhull!", 7);


	return (0);
}
