/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AServer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:45:35 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 14:13:22 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AServer.hpp"

SERVER::AServer::AServer(int domain, int service, int protocol,
int port, u_long interface, int backlog)
{
    _serverSocket = new SOCKET::ListenSocket(domain, service, protocol, port, interface, backlog);
	_htmlFile = loadHtmlFile("HtmlFile1.html");
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

std::string	SERVER::AServer::loadHtmlFile(std::string htmlFile)
{	
	std::string file = "Network/HtmlFiles/" + htmlFile;
	std::cout << file << std::endl;
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
	ifs.close();
	std::cout << "\n****TMP****\n" << tmp << "\n";
	return (tmp);
}

std::string	SERVER::AServer::getHtmlFile(void) const
{
	return (_htmlFile);
}
