/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:35:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 22:31:10 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	nothing(t_kift *kift)
{
	(void)kift;
}

void	invalid(t_kift *kift)
{
	system("say -v Samantha Invalid command motherfucker");
	fprintf(kift->fp,"OUTPUT: Invalid command motherfucker\n\n");
}

void	history(t_kift *kift)
{
	system("open -a TextEdit commands_log.txt");
	system("say -v Samantha SMH, log is already in the web UI dumbass..");
	fprintf(kift->fp,"OUTPUT: SMH, log is already in the web UI dumbass..\n\n");
}

void	bye(t_kift *kift)
{
	system("say -v Samantha byeeeeeeee");
	fprintf(kift->fp,"OUTPUT: byeeeeeeee\n\n");
}