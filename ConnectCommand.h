#ifndef CONNECT_COMMAND_H
#define CONNECT_COMMAND_H

#include "Command.h"
#include <thread>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <chrono>
#include <string.h>
#include <arpa/inet.h>
#include "ExpressionReader.h"
#include "ExpressionFactory.h"

/**
 * The main class of connect command.
 */
class ConnectCommand : public Command {
private:
    thread thread1;
    int client_socket;
    ExpressionFactory* ef;
    bool run;
public:
    /**
     * Constructor.
     * @param expressionFactory the expression factory.
     */
    ConnectCommand(ExpressionFactory* expressionFactory) {
        this->ef = expressionFactory;
        this->run = false;
    }
    virtual int execute(list<string>::iterator place, list<string>::iterator end);
    /**
     * join the thread.
     */
    void join() {
        if (this->run) {
            this->thread1.join();
        }
    }
    /**
     * Destructor.
     */
    ~ConnectCommand() {
        close(this->client_socket);
    }
    /**
     * Send a message to the server.
     * @param msg
     */
    void sendToServer(char* msg);
};
/**
 * Connect to the server.
 * @param port the port.
 * @param addr the address.
 * @param client_socket  the client socket.
 * @return the error.
 */
int connectControlClient(int port, const char* addr, int* client_socket);

#endif //CONNECT_COMMAND_H
