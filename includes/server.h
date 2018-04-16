/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 15:45:47 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 22:31:40 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
**	INCLUDES
*/

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <time.h>
# include "../libft/libft.h"

/*
**	MACROS
*/

# define PORT 5211
# define LOG_FILE "commands_log.txt"
# define TRUE 1
# define FALSE 0

# define ALARM 0
# define TIMER 1
# define LIGHT_ON 2
# define LIGHT_OFF 3
# define EMAIL 4
# define WEATHER 5
# define WHO 6
# define WHERE 7
# define MUSIC 8
# define SEARCH 9
# define HISTORY 10
# define EXIT 11
# define INVALID 12
# define EXTRA3 13
# define EXTRA4 14
# define EXTRA5 15

/*
**	DATA STRUCTURES
*/

typedef struct	s_kift
{
	FILE	*fp;
	int		socket;
	time_t	timer;
	char	input[128];
	void	(*table[16])(struct s_kift *kift);
}				t_kift;


/*
**	FUNCTIONS
*/



int		process_command(t_kift *kift);
void	bye(t_kift *kift);
void	invalid(t_kift *kift);
void	history(t_kift *kift);

void	error(void);
void	initialize_server(t_kift *kift);
void	create_socket(int *new_socket);
void	jump_table(t_kift *kift);

#endif