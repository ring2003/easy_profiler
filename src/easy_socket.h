/**
Lightweight profiler library for c++
Copyright(C) 2016  Sergey Yagovtsev

This program is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
**/
#ifndef EASY________SOCKET_________H
#define EASY________SOCKET_________H

#include <stdint.h>

#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#else

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#endif

class EasySocket
{
#ifndef _WIN32
    int m_socket = 0;
    uint16_t m_port = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server = nullptr;
#else
    SOCKET m_socket = 0;
    struct addrinfo  *result = NULL;
    struct addrinfo   hints;
#endif

public:
    EasySocket();
    ~EasySocket();

    int write(const void *buf, size_t nbyte);
    int read(void *buf, size_t nbyte);

    bool setAddress(const char* serv, uint16_t port);
    int connect();
};

#endif // EASY________SOCKET_________H
