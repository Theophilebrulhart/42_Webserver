/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadersRequestInfo.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:53:21 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/13 22:14:37 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERSREQUESTINFO_HPP
# define HEADERSREQUESTINFO_HPP

# include <map>
# include <iostream>
# include <unistd.h>
# define MAP_STRING std::map<std::string, std::string> 

//********MainParsing*******//
void    requestParsing(std::string buffer, MAP_STRING &info);
void    printInfo(MAP_STRING &info);
void    formParsing(std::string &buffer, MAP_STRING &info, int socket);

//********GetInfo*******//

void	getInfo(std::string &buffer, MAP_STRING &info);
void    getMethod(std::string &buffer, MAP_STRING &info);
void	getSection(std::string &buffer, MAP_STRING &info, std::string toFind, std::string name);

//********GetFormValue*******//

void    getFormValue(std::string const &content, MAP_STRING &info);

#endif