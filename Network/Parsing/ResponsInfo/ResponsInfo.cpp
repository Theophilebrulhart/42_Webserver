/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponsInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:37:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 16:58:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResponsInfo.hpp"

RESPONS::ResponsInfo::ResponsInfo(MAP_STRING &info) : _info(info)
{
	RESPONS::GetHtml	htmlFile(_info);
	
	RESPONS::GetStatus	status(_info, htmlFile.getHtml());
	setRespons(status.getStatus());
	setRespons("\n");
	setRespons(htmlFile.getHtml());
    return ;
}

RESPONS::ResponsInfo::~ResponsInfo(void)
{
    return ;
}

void	RESPONS::ResponsInfo::setRespons(std::string const value)
{
	//std::cout << "respons : " << _respons << std::endl;
	if (_respons.empty())
		_respons = value + '\n';
	else
		_respons += value + '\n';
	//std::cout << "respons : " << _respons << std::endl << std::endl;
	return ;
}

std::string RESPONS::ResponsInfo::getRespons(void) const
{
	return (_respons);
}
