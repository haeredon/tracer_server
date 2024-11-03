#include "Receiver.h"
#include "Event.h"

#include <iostream>


Receiver::Receiver(int port) : port(port) {
    this->addr = {
        .sin_family = AF_INET,
        .sin_port = htons(this->port),
        .sin_addr = {
            .s_addr = INADDR_ANY
        }
    };
}

void Receiver::initialize() {
    this->socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if(this->socket_descriptor == -1) {
        printf("Failed to initialize socket: %d \n", errno);
        throw;
    }

    int ret = bind(this->socket_descriptor, (struct sockaddr*) &addr, sizeof(addr));

    if(ret == -1) {
        printf("Failed to bind socket: %d \n", errno);
        throw;
    }

    ret = listen(this->socket_descriptor, 10 /* backlog */);

    if(ret == -1) {
        printf("Failed to listen on socket: %d \n", errno);
        throw;
    }    
}

void Receiver::start() {
    std::cout << "Listening on port " << port << std::endl; 
    while(1) {        
        int clientSocket = accept(this->socket_descriptor, nullptr, nullptr);
        // recieving data
        uint8_t buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);        

        for(auto it = this->controllers.begin(); it != this->controllers.end() ; ++it) {
            (*it)->handle((event_t*) buffer);            
        }

        send(clientSocket, buffer, 10, 0);
        std::cout << "Message from client: " << buffer << std::endl;    
    }
}

void Receiver::addController(AbstractController* controller) {
    this->controllers.push_back(controller);
}

void Receiver::stop() {
    int ret = close(socket_descriptor);

    if(ret == -1) {
        printf("Failed to close socket: %d \n", errno);
        throw;
    }
}