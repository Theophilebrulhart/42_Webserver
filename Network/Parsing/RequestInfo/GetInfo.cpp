/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:34:27 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 20:57:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeadersRequestInfo.hpp"

void    getMethod(std::string &buffer, MAP_STRING &info)
{
    if ((buffer.find("GET", 0, 3)) != std::string::npos)
        info.insert(std::pair<std::string, std::string>("METHOD", "GET"));
    else if (buffer.find("POST", 0, 4) != std::string::npos)
        info.insert(std::pair<std::string, std::string>("METHOD", "POST"));
    else if (buffer.find("DELETE", 0, 6) != std::string::npos)
        info.insert(std::pair<std::string, std::string>("METHOD", "DELETE"));
    return ;
}

void	getPath(std::string &buffer, MAP_STRING &info, std::string toFind, std::string name)
{
	std::string	path;
	
	for (int i = buffer.find(toFind.c_str(), 0, toFind.size()); buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r'; i++)
	{
		path += buffer[i];
	}
	try 
	{
    	info.at(name) = path;
  	}
  	catch (const std::out_of_range& oor) 
	{
		info.insert(std::pair<std::string, std::string>(name, path));
  	}
	
	return ;
}

void	getSection(std::string &buffer, MAP_STRING &info, std::string toFind, std::string name)
{
	std::string path;
	
	int i = buffer.find(toFind.c_str(), 0, toFind.size());
	
	while (buffer[i] != ' ')
		i++;
	i++;
	while (buffer[i] && buffer[i] != '\n')
	{
		path += buffer[i];
		i++;
	}
	try 
	{
    	info.at(name) = path;
  	}
  	catch (const std::out_of_range& oor) 
	{
		info.insert(std::pair<std::string, std::string>(name, path));
  	}
}

void	getInfo(std::string &buffer, MAP_STRING &info)
{
	getMethod(buffer, info);
    getPath(buffer, info, "/", "PATH");
    getPath(buffer, info, "HTTP/", "PROTOCOL");
	getSection(buffer, info, "Host:", "HOST");
	getSection(buffer, info, "Connection:", "CONNECTION");
	getSection(buffer, info, "Referer:", "REFERER");
}