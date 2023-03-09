/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponsInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:37:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/09 11:29:37 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponsInfo.hpp"

RESPONS::ResponsInfo::ResponsInfo(MAP_STRING &info) : _info(info)
{
	if (_info.at("PATH").find(".html") != std::string::npos || _info.at("PATH").find(".css") != std::string::npos)
	{
		getHtmlFile(_info.at("PATH"));
		setRespons(_status);
		setRespons(_contentType);
		// std::cout << "contentLength : " << _contentLength << "\n";
		//setRespons(_contentLength);
		setRespons("\r\n");
	}

	setRespons(_htmlFile);
    return ;
}

RESPONS::ResponsInfo::~ResponsInfo(void)
{
    return ;
}

void	RESPONS::ResponsInfo::setRespons(std::string const value)
{
	if (_respons.empty())
		_respons = value;
	else
		_respons += value;
	return ;
}

std::string RESPONS::ResponsInfo::getRespons(void) const
{
	return (_respons);
}

void		RESPONS::ResponsInfo::getHtmlFile(std::string const &file)
{
	std::cout << "\ngetHtml from responsinfo\n";
	RESPONS::GetHtml htmlFile(_info, file);
	RESPONS::GetStatus	status(_info, htmlFile.getHtml());
	setStatus(status.getStatus());
	setContentType(htmlFile.getContentType());
	setHtmlFile(htmlFile.getHtml());
	setContentLength(htmlFile.getContentLength());
	return ;
}

void	RESPONS::ResponsInfo::setHtmlFile(std::string const &htmlFile)
{
	_htmlFile = htmlFile;
	return ;
}

void	RESPONS::ResponsInfo::setStatus(std::string const &status)
{
	_status = status;
	return ;
}

void	RESPONS::ResponsInfo::setContentType(std::string const &contentType)
{
	_contentType = contentType;
	return ;
}

void	RESPONS::ResponsInfo::setContentLength(std::string const &contentLength)
{
	_contentLength = contentLength;
	return ;
}