/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadersRequestInfo.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:53:21 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/06 15:55:46 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERSREQUESTINFO_HPP
# define HEADERSREQUESTINFO_HPP

# include <map>
# include <iostream>
# define MAP_STRING std::map<std::string, std::string> 

//********MainParsing*******//
std::map<std::string, std::string>  &requestParsing(std::string buffer, MAP_STRING &info);
void    							printInfo(MAP_STRING &info);

//********GetInfo*******//

void	getInfo(std::string &buffer, MAP_STRING &info);
void    getMethod(std::string &buffer, MAP_STRING &info);
void	getSection(std::string &buffer, MAP_STRING &info, std::string toFind, std::string name);

#endif