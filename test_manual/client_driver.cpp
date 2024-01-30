#include <iostream>
#include <string>

#include "client_server.hpp"

int main() {
    // Print the received message to terminal.
    std::cout << receiveOnClient() << std::endl;
    return 0;
}