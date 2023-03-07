/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:10:19 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/07 17:13:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AllHeaders.hpp"

class mystring
{
    public: void _fill_string(std::string const &);
    private: std::string _asdf;
};

void mystring::_fill_string(std::string const & to_append)
{
    _asdf += to_append; std::cout << _asdf << '\n';
}

int main(void)
{
//     mystring asdf;
//     std::string jean("Jean");
//   asdf._fill_string(jean);
//     asdf._fill_string(jean);
//     asdf._fill_string("1234");
//     asdf._fill_string("1234");
  


//     return 0;
    SERVER::TestServer t;
    return (0);
}