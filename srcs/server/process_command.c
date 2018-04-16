/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:05:45 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 22:34:33 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static	int	parse_command(char *s)
{
	int	n;

	n = INVALID;
	(ft_strstr(s, "history") ? n = HISTORY : 0);
	(ft_strstr(s, "exit") ? n = EXIT : 0);
	return (n);
}

int			process_command(t_kift *kift)
{
	int command;

	// ft_putstr("TEST1");
	command = parse_command(kift->input);
	// ft_putstr("TEST2");
	// time(&(kift->timer));
	fprintf(kift->fp, "COMMAND: %s\n", kift->input);
	// ft_putstr("TEST3");
	kift->table[command](kift);
	// ft_putstr("TEST4");
	if (command == EXIT)
		return (0);
	else
		return (1);
}