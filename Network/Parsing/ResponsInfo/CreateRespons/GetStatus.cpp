/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetStatus.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:04:53 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/08 13:05:55 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetStatus.hpp"

RESPONS::GetStatus::GetStatus(MAP_STRING &info, std::string html) : _info(info), _html(html)
{
	setStatus(info.at("PROTOCOL"));
	if (!_html.empty())
		setStatus(" 200 OK\r\n");
	else
		setStatus(" 404 Not Found\r\n");
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
		_status = value;
	else
		_status += value;
	return ;
}