#include <gtest/gtest.h>
#include <thread>

#include "client_server.hpp"

/**
 * Testing fixture for the client server functions.
 */
class ClientServerTest : public ::testing::Test {
protected:
    /**
     * The string received by the client.
     */
    std::string receivedString_;
    
    /**
     * The string that should be received by the client.
     */
    const std::string kCorrectReceivedString_ = "Hail to the Victors!";

public: 
    /**
     * Set the value of the received string by running the client function.
     */
    void setReceivedString() {
        receivedString_ = receiveOnClient();
    }
};

/**
 * Check if the server can send the correct string to the client.
 */
TEST_F(ClientServerTest, SendReceive) {
    std::thread server_thread(&sendOnServer);
    std::thread client_thread(&ClientServerTest::setReceivedString, this);
    server_thread.join();
    client_thread.join();
    ASSERT_EQ(receivedString_, kCorrectReceivedString_);
}
