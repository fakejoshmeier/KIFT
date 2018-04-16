/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 20:09:41 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/15 22:27:02 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
**	INCLUDES
*/

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "../libft/libft.h"

/*
**	MACROS
*/

# define PORT 5211
# define TRUE 1
# define FALSE 0

/*
**	STRUCTURES
*/


/*
**	FUNCTIONS
*/

void	error(void);

#endif