//
// Created by amir on 31/12/2019.
//

#include "ConnectCommand.h"

int ConnectCommand::execute(string *place) {
    //todo from arguments
    this->thread1 = thread(connectControlClient, 5402, "127.0.0.1");
    this_thread::sleep_for(chrono::seconds(1));
    return 3;
}

int connectControlClient(int port, const char* addr) {
    Command::lock();
    //create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return -1;
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(addr);  //the localhost address
    address.sin_port = htons(port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server"<<std::endl;
        return -2;
    } else {
        std::cout<<"Client is now connected to server" <<std::endl;
    }

    //if here we made a connection
    const char* hello = "Hi from client";
    int is_sent = send(client_socket , hello , strlen(hello), 0 );
    if (is_sent == -1) {
        std::cout<<"Error sending message"<<std::endl;
    } else {
        std::cout<<"Hello message sent to server" <<std::endl;
    }


    close(client_socket);
    Command::unlock();
    return 0;
}