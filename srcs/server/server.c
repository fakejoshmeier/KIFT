/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:25:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 22:22:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

/*
**	https://www.geeksforgeeks.org/socket-programming-cc/
**	Creates TCP socket which listens to customizable port over ipv4
**
**
*/

int				main(void)
{
	t_kift	*kift;

	
	kift = (t_kift *)ft_memalloc(sizeof(kift));
	initialize_server(kift);
	while (TRUE)
	{
		recv(kift->socket, kift->input, 128, 0);
		if (ft_strlen(kift->input) > 0)
		{
			if (process_command(kift) == 0)
				break ;
		}
	}
	fclose(kift->fp);
	return (0);
}