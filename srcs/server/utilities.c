/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:05:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 22:32:05 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

void	create_socket(int *new_socket)
{
	int					server_fd;
	int					opt;
	int					address_len;
	struct	sockaddr_in	address;

	opt = 1;
	address_len = sizeof(address);
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		error();
	ft_bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	bind(server_fd, (struct sockaddr *)&address, sizeof(address));
	listen(server_fd, 6);
	if ((*new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address_len)) < 0)
		error();
}

void	initialize_server(t_kift *kift)
{
	kift->fp = fopen(LOG_FILE, "a+");
	kift->timer = (time_t)ft_memalloc(sizeof(time_t));
	create_socket(&kift->socket);
	jump_table(kift);
}

void	jump_table(t_kift *kift)
{
	kift->table[HISTORY] = &history;
	kift->table[INVALID] = &invalid;
	kift->table[EXIT] = &bye;
}
