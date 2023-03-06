/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AServer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:45:35 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/02 17:52:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AServer.hpp"

SERVER::AServer::AServer(int domain, int service, int protocol,
int port, u_long interface, int backlog)
{
    _serverSocket = new SOCKET::ListenSocket(domain, service, protocol, port, interface, backlog);
	_loadHtmlFile();
    return ;
}

SERVER::AServer::~AServer(void)
{
    return ;
}

SOCKET::ListenSocket *SERVER::AServer::getServerSocket(void) const
{
	return (_serverSocket);
}

void	SERVER::AServer::_loadHtmlFile(void)
{
	std::string	file = "Network/HtmlFiles/HtmlFile1.html";
	std::string	tmp;
	std::ifstream ifs (file.c_str(), std::ifstream::in);
	if(ifs.fail())
	{
		std::cout << "Failed to open HTML file\n";
		exit (EXIT_FAILURE);
	}
	char	c = ifs.get();
	while (ifs.good())
	{
		tmp += c;
		c = ifs.get(); 
	}
	setHtmlFile(tmp);
	ifs.close();
	return ;
}

void	SERVER::AServer::setHtmlFile(std::string htmlFile)
{
	_htmlFile = htmlFile;
	return ;
}

std::string	SERVER::AServer::getHtmlFile(void)
{
	return (_htmlFile);
}