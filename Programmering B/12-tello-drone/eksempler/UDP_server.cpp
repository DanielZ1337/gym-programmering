//
// UDP_server.cpp
// ~~~~~~~~~~
//
// Small demo of an UDP server using asio c++.
//

#include <iostream>
#include <string>
#include "asio.hpp"
using namespace std;
using asio::ip::udp;

// Which local port should we listen to?
const short PORT = 5000;

int main()
{
    try
    {
        // Setup io_context that will handle input/output
        asio::io_context io_context;

        // Local and remote endpoints (remote is still unknown)
        udp::endpoint local_endpoint(udp::v4(),PORT);
        udp::endpoint remote_endpoint;

        // Socket for listening (using local endpoint)
        udp::socket socket(io_context,local_endpoint);

        // Listen for message (and update remote endpoint when received)
        string receive_buffer(1000,' ');
        size_t length = socket.receive_from(asio::buffer(receive_buffer),remote_endpoint);

        // Send response to the remote endpoint
        string send_buffer = "[ECHO] " + receive_buffer.substr(0,length);
        socket.send_to(asio::buffer(send_buffer),remote_endpoint);

        // Print received message.
        cout << "Received: " << receive_buffer.substr(0,length) << endl;

    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
