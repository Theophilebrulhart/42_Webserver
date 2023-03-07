/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResponsInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:32:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 22:00:25 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSINFO_HPP
# define RESPONSINFO_HPP
# include "HeadersResponsInfo.hpp"


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
			void		getHtmlFile(void);

			void		setHtmlFile(std::string const &htmlFile);
			void		setStatus(std::string const &status);
			void		setContentType(std::string const &contentType);

		private:

			std::string	_respons;
			std::string _htmlFile;
			std::string	_status;
			std::string	_contentType;
			MAP_STRING	_info;
	};
}

# include "../../Server/HeadersServer.hpp"
#endif