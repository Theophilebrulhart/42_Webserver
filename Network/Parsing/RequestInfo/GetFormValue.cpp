/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetFormValue.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:11:39 by theophilebr       #+#    #+#             */
/*   Updated: 2023/03/14 17:35:09 by tbrulhar         ###   ########.fr       */
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
			//std::cout << "i : " << i << "\n";
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

void	loadProfilPic(std::string const &buffer, MAP_STRING &info, std::string toFind, std::string name, int i)
{
	// std::string value;

	// for (int j = buffer.find(toFind.c_str(), 0, toFind.size()); j < i; j++)
	// {
	// //std::cout << "\e[0;31m****i*****\n" << i << "\n";

	// 	value += buffer[j];
	// }
	// //std::cout << "\e[0;31m****value*****\n" << value << "\n";
	// try 
	// {
	// 	info.at(name) = value;
	// }
	// catch (const std::out_of_range& oor) 
	// {
	// 	info.insert(std::pair<std::string, std::string>(name, value));
	// }
}

void	getProfilPic(std::string const &buffer, MAP_STRING &info, std::string toFind, std::string name)
{
	std::string	path;
	std::string imgName;
	std::string extension;
	
	for (int j = buffer.find(toFind.c_str(), 0, toFind.size()) + toFind.size(); buffer[j] != '\n' && buffer[j] != '\r'; j++)
	{
		if (buffer[j] == '"')
			j++;
		imgName += buffer[j];
	}
	std::cout << "\n image name : " << imgName << "\n\n";
	for (int i = imgName.find("."); imgName[i] && imgName[i] != '\r'; i++)
		extension += imgName[i];
	std::cout << "\n EXTENSIOn : " << extension << "\n\n";
	if (extension == ".svg")
		loadProfilPic(buffer, info, "<svg", name, buffer.find("</svg>") + 6);
	try 
	{
		info.at("IMAGENAME") = imgName;
	}
	catch (const std::out_of_range& oor) 
	{
		info.insert(std::pair<std::string, std::string>("IMAGENAME", imgName));
	}
	return ;
}

void    getFormValue(std::string const &content, MAP_STRING &info)
{
    getValue(content, info, "firstname", "FIRSTNAME");
	getValue(content, info, "sport", "SPORT");
	getProfilPic(content, info, "filename=", "PROFILPIC");
}