/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetHtml.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:24:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/09 11:11:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetHtml.hpp"

RESPONS::GetHtml::GetHtml(MAP_STRING &info, std::string const &file) : _info(info)
{
	_html = loadHtmlFile(file);
	//if (_info.at("PATH").find(".css") != std::string::npos)
	if (file.find(".html") != std::string::npos)
		_contentType = "Content-Type: text/html\r\n";
	else if ( file.find(".css") != std::string::npos)
		_contentType = "Content-Type: text/css\r\n";
	std::string size = ft_itoa(_html.size());
	_contentLength = "Content-Length : " + size + "\r\n";
    return ;
}

RESPONS::GetHtml::~GetHtml(void)
{
    return ;
}


std::string	RESPONS::GetHtml::loadHtmlFile(std::string htmlFile)
{	
	std::string file = "Network/HtmlFiles/" + htmlFile;
	std::string	tmp;
	std::ifstream ifs (file.c_str(), std::ifstream::in);
	if(ifs.fail())
	{
		std::cout << "\nopen html file failed \n\n";
		return (tmp);
	}
	char	c = ifs.get();
	while (ifs.good())
	{
		tmp += c;
		c = ifs.get(); 
	}
	ifs.close();
	return (tmp);
}

std::string	RESPONS::GetHtml::getHtml(void) const
{
	return (_html);
}

std::string RESPONS::GetHtml::getContentType(void) const
{
	return (_contentType);
}

std::string RESPONS::GetHtml::getContentLength(void) const
{
	return (_contentLength);
}

