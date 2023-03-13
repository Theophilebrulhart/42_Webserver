/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetFormValue.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:11:39 by theophilebr       #+#    #+#             */
/*   Updated: 2023/03/13 22:55:43 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeadersRequestInfo.hpp"

void	getValue(std::string const &buffer, MAP_STRING &info, std::string toFind, std::string name)
{
	std::string	path;
	
	if (buffer.find(toFind.c_str(), 0, toFind.size()) != std::string::npos)
	{
		int i = buffer.find(toFind.c_str(), 0, toFind.size()) + toFind.size();
		while (buffer[i] != '\n' && buffer[i])
			i++;
		while (buffer[i] == '\n' || buffer[i] == '\r')
		{
			i++;
			std::cout << "i : " << i << "\n";
		}
			
		while (buffer[i] != '\n' && buffer[i])
		{
			path += buffer[i];
			i++;
		}
		std::cout << "\n PATH : "<< path << "\n\n";
		try 
		{
			info.at(name) = path;
		}
		catch (const std::out_of_range& oor) 
		{
			info.insert(std::pair<std::string, std::string>(name, path));
		}
	}
	return ;
}


void    getFormValue(std::string const &content, MAP_STRING &info)
{
    getValue(content, info, "firstname", "FIRSTNAME");
	getValue(content, info, "sport", "SPORT");
	getValue(content, info, "Content-Type:", "PROFILPIC");
}