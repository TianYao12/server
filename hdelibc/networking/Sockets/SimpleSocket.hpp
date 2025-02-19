#ifndef SIMPLE_SOCKET_HPP
#define SIMPLE_SOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace HDE
{
    class SimpleSocket
    {
        struct sockaddr_in address;
        int sock, connection;

    public:
        SimpleSocket(int, int, int, int, u_long);

        virtual int connectToNetwork(int, struct sockaddr_in) = 0;

        // Test return value of socket(), bind(), connect(), listen() for success or failure status
        void validateSocketOperation(int); 

        // Below are gettors and settors
        struct sockaddr_in getAddress();
        int getSock();
        int getConnection();
        void setConnection(int);
    };
};

#endif