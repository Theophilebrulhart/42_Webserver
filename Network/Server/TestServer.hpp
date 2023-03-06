/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:54:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/02 16:44:33 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTSERVER_HPP
# define TESTSERVER_HPP
# include <iostream> 
# include "AServer.hpp"
# include <unistd.h>

namespace   SERVER
{
    class TestServer : public AServer
    {
        public:
            TestServer();
            ~TestServer(void);
            
            void    launch(void);
            

        private:

            char    _buffer[3000];
            int     _newSocket;
            void    _accepter(void);
            void    _handler(void) const;
            void    _responder(void);
    };
}



#endif