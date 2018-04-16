/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:37:38 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 21:52:13 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(void)
{
	char				*line;
	int					sock;
	struct sockaddr_in	server_address;

	sock = 0;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error();
	ft_bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
		error();
	connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
	while (TRUE)
	{
		get_next_line(0, &line);
		send(sock, line, ft_strlen(line), 0);
		if (ft_strequ(line, "exit") == 1)
			break ;
	}
	return (0);
}