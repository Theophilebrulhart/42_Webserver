/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetHtml.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:24:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 16:43:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetHtml.hpp"

RESPONS::GetHtml::GetHtml(MAP_STRING &info) : _info(info)
{
	std::string html;
	if (_info.at("PATH").find(".html") != std::string::npos)
		_html = loadHtmlFile(_info.at("PATH"));
	else
		_html = loadHtmlFile("HtmlFile1.html");
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
		return (NULL);
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
