/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:57:16 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/14 17:19:59 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestServer.hpp"

SERVER::TestServer::TestServer() : AServer(AF_INET, SOCK_STREAM, 0, 80,
INADDR_ANY, 35)
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
	char			buf[3000];

    _newSocket = accept(getServerSocket()->getSocketFd(), (struct sockaddr *)&address,
                        (socklen_t *)&addrlen);
	if (_newSocket < 0)
	{
		std::cerr << "Failed to accept socket\n";
		exit (EXIT_FAILURE);
	}
		bzero(buf, 3000);
    	read(_newSocket, buf, 3000);
		_buffer = buf;
	//std::cout << _buffer << std::endl;
	return ;
}

void	SERVER::TestServer::_handler(void)
{
	requestParsing(_buffer, _requestInfo);
	if (_requestInfo.at("METHOD") == "POST")
	{
		try
		{
			_requestInfo.at("CONTENT-TYPE");
			formParsing (_buffer, _requestInfo, _newSocket);
		}
		catch(const std::out_of_range& oor)
		{
			std::cout << "\nNo multipart/form-data\n";
		}
	}
	return ;
}

void	SERVER::TestServer::_responder(void)
{
	RESPONS::ResponsInfo	createRespons(_requestInfo);
	std::string respons = createRespons.getRespons();
	std::cout << "\n\e[0;93m*****RESPONDER****\n" << respons;
	send(_newSocket, respons.c_str(), respons.size(), 0);
	//std::cout << "send done\n";
	close(_newSocket);
	return ;
}

void	SERVER::TestServer::launch(void)
{
	std::cout << "\e[0;31m****STARTING*****\e[0m\n";
	while (1)
	{
		std::cout << "\n\e[0;32m===== WAITING =====\e[0m\n";
		_accepter();
		_handler();
		_responder();
		std::cout << "\e[0;36m\n===== DONE =====\e[0m\n";
	}
	return ;
}
