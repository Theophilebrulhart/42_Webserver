/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:57:16 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/02 17:18:57 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestServer.hpp"

SERVER::TestServer::TestServer() : AServer(AF_INET, SOCK_STREAM, 0, 80,
INADDR_ANY, 10)
{
	launch();
    return ;
}

SERVER::TestServer::~TestServer(void)
{
    return ;
}

void    SERVER::TestServer::_accepter(void)
{
    struct  sockaddr_in address = getServerSocket()->getAddress();
    int     addrlen = sizeof(address);
    _newSocket = accept(getServerSocket()->getSocketFd(), (struct sockaddr *)&address,
                        (socklen_t *)&addrlen);
	if (_newSocket < 0)
	{
		std::cerr << "Failed to accept socket\n";
		exit (EXIT_FAILURE);
	}
    read(_newSocket, _buffer, 3000);
	return ;
}

void	SERVER::TestServer::_handler(void) const
{
	std::cout << "\n********* BUFFER ***********\n\n " << _buffer;
	return ;
}

void	SERVER::TestServer::_responder(void)
{
	std::string htmlFile = getHtmlFile();
	send(_newSocket, htmlFile.c_str(), htmlFile.size(), 0);
	close(_newSocket);
	return ;
}

void	SERVER::TestServer::launch(void)
{
	while (1)
	{
		std::cout << "\n===== WAITING =====\n\n";
		_accepter();
		_handler();
		_responder();
		std::cout << "\n===== DONE =====\n\n";
	}
	return ;
}
