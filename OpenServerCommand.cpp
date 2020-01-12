#include "OpenServerCommand.h"

int OpenServerCommand::execute(list<string>::iterator place, list<string>::iterator end) {
    list<string>::iterator it = place;
    it++;
    ExpressionReader er;
    list<string> l = er.getExpressions(it, end);
    Expression* e = this->ef->create(l);
    this->run = true;
    this->thread1 = thread(openServer, e->calculate(), this->sv, this->vm);
    this_thread::sleep_for(chrono::seconds(1));
    delete(e);
    return 1 + l.size();
}

int openServer(int port, SimVariables sv, VariablesMap* vm) {
    Command::lock();
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        throw "Error";
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
        throw "Error";
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        throw "Error";
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        close(socketfd);
        throw "Error";
    }

    close(socketfd); //closing the listening socket
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, 1024);

    if (valread > 1) {
        unsigned int i = 0;
        for (string s : sv.get()) {
            string sub = "";
            while (buffer[i] != ',') {
                sub += buffer[i];
                i++;
                if(i >= 1024) {
                    break;
                }
            }
            i++;
            vm->set(s, stod(sub));
            if(i >= 1024) {
                break;
            }
        }
    }

    Command::unlock();

    buffer[1024] = {0};

    valread = read(client_socket, buffer, 1024);

    //reading from client
    while (valread != 0) {


        Command::lock();
        if (valread > 1) {
            unsigned int i = 0;
            for (string s : sv.get()) {
                string sub = "";
                while (buffer[i] != ',') {
                    sub += buffer[i];
                    i++;
                    if(i >= 1024) {
                        break;
                    }
                }
                i++;
                vm->set(s, stod(sub));
                if(i >= 1024) {
                    break;
                }
            }
        }
        Command::unlock();
        buffer[1024] = {0};

        valread = read(client_socket, buffer, 1024);
    }
    return 0;
}
