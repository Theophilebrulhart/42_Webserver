/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:10:19 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/03/02 14:27:17 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AllHeaders.hpp"

int main(void)
{
    // std::cout << "Starting...\n";
    // std::cout << "Binding Socket..\n";
    // SOCKET::BindSocket  bs = SOCKET::BindSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY);
    // std::cout << "Listenin Socket...\n";
    // SOCKET::ListenSocket ls = SOCKET::ListenSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
    // std::cout << "Success..\n";

    SERVER::TestServer t;
    return (0);
}