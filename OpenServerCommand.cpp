//
// Created by amir on 30/12/2019.
//

#include "OpenServerCommand.h"

int OpenServerCommand::execute(string *place) {
    this->thread1 = thread(openServer, strToInt(*(place + 1)));
    this_thread::sleep_for(chrono::seconds(1));
    return 2;
}

int openServer(int port) {
    Command::lock();
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        close(socketfd);
        return -4;
    }

    close(socketfd); //closing the listening socket
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);
    if (valread > 1) {
        std::cout << buffer << std::endl;
    }
    Command::unlock();
    //reading from client
    while (valread != 0) {

        buffer[1024] = {0};

        valread = read(client_socket, buffer, 1024);
        Command::lock();
        if (valread > 1) {
            std::cout <<valread <<" : " << buffer << std::endl;
        }
        Command::unlock();
    }
}