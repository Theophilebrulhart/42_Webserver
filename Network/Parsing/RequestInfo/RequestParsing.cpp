/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestParsing.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:02:35 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/06 15:57:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeadersRequestInfo.hpp"

void    printInfo(MAP_STRING &info)
{
    MAP_STRING::iterator it_b = info.begin();
    MAP_STRING::iterator it_e = info.end();

	std::cout << "\n\n*****REQUEST INFO PRINT******\n";
    while (it_b != it_e)
    {
        std::cout << it_b->first << " : " << it_b->second << "\n"; 
        ++it_b;
    }
}

std::map<std::string, std::string>  &requestParsing(std::string buffer, MAP_STRING &info)
{
    std::cout << "\n\nmain parsing buffer : " << buffer << "\n\n";
    getInfo(buffer, info);
    printInfo(info);
    return (info);
}