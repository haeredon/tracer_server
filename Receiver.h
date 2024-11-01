#ifndef TRACE_SERVER_RECEIVER_H
#define TRACE_SERVER_RECEIVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <functional>
#include <vector>

// do asynch accept
// call receivehandlers in other threads
// adjust receive size/always get full request
// this class could be split in 2. One for interfacing the os network api and another for actually getting the data
// make it abstract so that we can also get IPC through same interface
class Receiver {

    private:
        
        int port;

        int socket_descriptor;

        struct sockaddr_in addr;

        std::vector<std::function<void(uint8_t*)>> receiveHandlers;

    public:

        Receiver(int port);

        void initialize();

        void start();

        void stop();

        void addReceiveHandler(std::function<void(uint8_t*)> handler);

};




#endif // TRACE_SERVER_RECEIVER_H