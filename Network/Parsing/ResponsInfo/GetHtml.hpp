/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetHtml.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:25:04 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 16:23:23 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETHTML_HPP
# define GETHTML_HPP
# include <fstream>
# include "GetStatus.hpp"
# include <map>
# include <iostream>
# define MAP_STRING std::map<std::string, std::string>

namespace RESPONS
{
	class GetHtml
	{
		public:
			GetHtml(MAP_STRING &info);
			~GetHtml(void);

			std::string	getHtml(void) const;
			std::string	loadHtmlFile(std::string htmlFile);

		private:

			std::string	_html;
			MAP_STRING	_info;
	};
}



#endif