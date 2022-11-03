/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux-readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:56:30 by rlins             #+#    #+#             */
/*   Updated: 2022/11/03 18:19:42 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void aux_readline()
{
	char	*usr_input;

	// echo -e " \033[5;1;32m $> \033[0m"
	// echo -e " \033[5;1;32m $> \033[0m"


	// usr_input = readline("$> ");
	// usr_input = readline("🔥 $>");
	//https://gist.github.com/avelino/3188137

	// Prompt blink
	usr_input = readline("\001\e[5;1;32m\033>>$\001\e[0m\002 ");

	printf("\n%s\n", usr_input);

}
