/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetHtml.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:25:04 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/09 11:10:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETHTML_HPP
# define GETHTML_HPP
# include <fstream>
# include "GetStatus.hpp"
# include <map>
# include <iostream>
# include "Utils.hpp"
# define MAP_STRING std::map<std::string, std::string>

namespace RESPONS
{
	class GetHtml
	{
		public:
			GetHtml(MAP_STRING	&info, std::string const &file);
			~GetHtml(void);

			std::string	getHtml(void) const;
			std::string getContentType(void) const;
			std::string	getContentLength(void) const;
			
			std::string	loadHtmlFile(std::string htmlFile);

		private:

			std::string	_html;
			std::string	_contentType;
			std::string	_contentLength;
			MAP_STRING	_info;
	};
}



#endif