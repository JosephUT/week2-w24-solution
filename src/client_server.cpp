// TODO: Update your includes as necessary.
// Begin solution code.
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <array>
#include <iostream>
#include <string>
#include <stdexcept>
// End solution code.

#include "client_server.hpp"

void sendOnServer() {
    // TODO: Set up the loopback address and a port to bind the server to.
    // Begin solution code.
    static int const PORT = 8080;
    static std::string const kHOST{"127.0.0.1"};

    struct sockaddr_in server_address {};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_aton(kHOST.data(), &server_address.sin_addr) < 0) {
        throw std::runtime_error("Failed to convert address");
    }
    // End solution code.

    // TODO: Set up a socket.
    // Begin solution code.
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        throw std::runtime_error("Error creating socket");
    }
    // End solution code.

    // TODO: Bind the socket to the address and port.
    // Begin solution code.
    if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&server_address), sizeof(server_address)) < 0) {
        throw std::runtime_error("Failed to bind to port");
    }
    // End solution code.

    // TODO: Listen on the socket.
    // Begin solution code.
    if (listen(server_fd, 10) < 0) {
        throw std::runtime_error("Failed to listen");
    }
    // End solution code.

    // TODO: Accept a client connection.
    // Begin solution code.
    int connection_fd = accept(server_fd, nullptr, nullptr);
    if (connection_fd < 0) {
        throw std::runtime_error("Failed to accept connection");
    }
    // End solution code.

    // TODO: Send the string "Hail to the Victors!" over the socket.
    // Begin solution code.
    static std::string const message = "Hail to the Victors!";
    if (send(connection_fd, message.data(), message.size(), 0) < 0) {
        throw std::runtime_error("Error sending message");
    }
    // End solution code.

    // TODO: Close the sockets.
    // Begin solution code.
    close(server_fd);
    close(connection_fd);
    // End solution code.
}

std::string receiveOnClient() {
    // TODO: Set up the address and port of the server to be used for connect().
    // Begin solution code.
    static int const kServerPort = 8080;
    static std::string const kServerAddress = "127.0.0.1";

    struct sockaddr_in serverAddress {};
    struct sockaddr_in clientAddress {};

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(kServerPort);
    if (inet_aton("127.0.0.1", &serverAddress.sin_addr) < 0) {
        throw std::runtime_error("Error binding server host to address");
    }
    // End solution code.

    // TODO: Set up a socket.
    // Begin solution code.
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        throw std::runtime_error("Error creating socket");
    }
    // End solution code.

    // TODO: Connect the socket to the server in server.cpp. Loop and retry connecting until success.
    // Begin solution code.
    int connected = -1;
    while (connected < 0) {
        connected = connect(client_fd, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress));
    }
    // End solution code.

    // TODO: Allocate a buffer big enough to hold the string. Receive on the socket.
    /* 
     * NOTE: If you make the buffer big enough and you are using the loopback address,
     *       then you will get the whole string on one recv() call. This does not
     *       apply in general. There is no gaurantee on all bytes being sent or received.
     */ 
    // Begin solution code.
    std::array<char, 1024> buffer{};
    ssize_t recvSize = -1;
    if ((recvSize = recv(client_fd, buffer.data(), buffer.size(), MSG_NOSIGNAL)) < 0) {
        throw std::runtime_error("Error receiving message");
    }
    // End solution code.

    // TODO: Close the socket.
    // Begin solution code.
    close(client_fd);
    // End solution code.

    // TODO: Decode the string and return it.
    // Begin solution code.
    buffer[recvSize] = '\0';
    std::string message(buffer.begin(), recvSize);
    return message;
    // End solution code.
}
