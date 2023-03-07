/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetStatus.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:04:53 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 17:27:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetStatus.hpp"

RESPONS::GetStatus::GetStatus(MAP_STRING &info, std::string html) : _info(info), _html(html)
{
	setStatus(info.at("PROTOCOL"));
	if (!_html.empty())
		setStatus("\r200\rOK");
	else
		setStatus("\r404 Not\rFound");
    return ;
}

RESPONS::GetStatus::~GetStatus(void)
{
    return ;
}

std::string	RESPONS::GetStatus::getStatus(void) const
{
	return (_status);
}

void	RESPONS::GetStatus::setStatus(std::string const &value)
{

		if (_status.empty())
		{
			std::cout << "\"" << _status << "\" operator = \"" << value << "\""  << std::endl;
			_status = value;
		}
		
	else
		{
			std::cout << "\"" << _status << "\" operator += \"" << value << "\""  << std::endl;
			std::cout << "= status " << _status << std::endl;
			_status += value;

		}
	std::cout << "= status " << _status << std::endl;
	return ;
}