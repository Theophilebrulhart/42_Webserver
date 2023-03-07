/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponsInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:32:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 16:18:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSINFO_HPP
# define RESPONSINFO_HPP
# include <map>
# include <iostream>
# include "HeadersResponsInfo.hpp"
# define MAP_STRING std::map<std::string, std::string>


class TestServer;

namespace RESPONS
{
	class ResponsInfo
	{
		public:
			ResponsInfo(MAP_STRING &info);
			virtual ~ResponsInfo(void);
		
			void		setRespons(std::string const value);
			std::string	getRespons(void) const;

		private:

			std::string	_respons;
			MAP_STRING	_info;
	};
}

# include "../../Server/HeadersServer.hpp"
#endif