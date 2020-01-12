#include "ConnectCommand.h"

int ConnectCommand::execute(list<string>::iterator place, list<string>::iterator end) {
    list<string>::iterator it = place;
    int pass = 5;
    //get the address.
    it++;
    if (it == end) {
        throw "Error";
    }
    if (*it != "(") {
        throw "Error";
    }
    it++;
    if (it == end) {
        throw "Error";
    }
    string str = checkString(*it);
    if (str == "\"") {
        throw "Error";
    }
    char* a = (char*) malloc(sizeof(char) * str.length());
    if (a == nullptr) {
        throw "Error";
    }
    for (unsigned int i = 0; i < str.length(); ++i) {
        a[i] = str[i];
    }
    it++;
    if (it == end) {
        throw "Error";
    }
    if (*it != ",") {
        throw "Error";
    }
    //get the ')' iterator
    list<string>::iterator iter = it;
    list<string>::iterator end2;
    while (iter != end) {
        if (*iter == "\n") {
            end2 = iter;
            end2--;
            break;
        }
        iter++;
    }
    if (iter == end) {
        throw "Error";
    }
    //get the port.
    it++;
    ExpressionReader er;
    list<string> l = er.getExpressions(it, end2);
    pass += l.size();
    Command::lock();
    Expression* e = this->ef->create(l);
    int p = (int) e->calculate();
    Command::unlock();
    if (it == end) {
        throw "Error";
    }
    if (*it != ")") {
        throw "Error";
    }
    this->run = true;
    this->thread1 = thread(connectControlClient, p, "127.0.0.1", &this->client_socket);
    this_thread::sleep_for(chrono::seconds(1));

    delete(a);
    delete(e);
    return pass;
}

int connectControlClient(int port, const char* addr, int* client_socket) {
    Command::lock();
    //create socket
    *client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (*client_socket == -1) {
        //error
        throw "Error";
    }

    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(addr);  //the localhost address
    address.sin_port = htons(port);
    //we need to convert our number (both port & localhost)
    // to a number that the network understands.

    // Requesting a connection with the server on local host with port 8081
    int is_connect = connect(*client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        throw "Error";
    } else {
        std::cout<<"Client is now connected to server" <<std::endl;
    }


    Command::unlock();
    return 0;
}

void ConnectCommand::sendToServer(char* msg) {
    int is_sent = send(this->client_socket , msg , strlen(msg), 0 );
    if (is_sent == -1) {
        std::cout<<"Error sending message"<<std::endl;
    }
}
