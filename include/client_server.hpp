#pragma once

/**
 * Start a server socket and send a string over it. The string should be "Hail to the Victors!".
 */
void sendOnServer();

/**
 * Connect a client socket and receive a string from it.
 * @return The received string.
 */
std::string receiveOnClient();
