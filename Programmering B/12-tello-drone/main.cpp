#include <iostream>
#include "asio.hpp"
#include "include_opencv.h"
#include <string>
using namespace std;
using asio::ip::udp;

// Target IP address and port
const asio::ip::address IP = asio::ip::make_address("192.168.10.1");
const short PORT = 8889;

int main()
{
    // Basic asio check
    asio::io_context io;
    if(io.stopped()) cout << "ASIO io_context stopped." << endl;
    else cout << "ASIO io_context is running." << endl;

    // Basic OpenCV check
    cout << "openCV version: " << CV_VERSION << endl;

    try
    {
        // Setup io_context that will handle input/output
        asio::io_context io_context;

        // Socket to send and receive the messages (using ip v4)
        udp::socket socket(io_context,udp::v4());

        // Remote endpoint with ip and port
        udp::endpoint endpoint(IP,PORT);

        // Use socket to send message to remote endpoint
        string send_buffer = "land";
        socket.send_to(asio::buffer(send_buffer), endpoint);

        // Use socket to receive response
        string response_buffer(1000,' ');
        size_t length = socket.receive(asio::buffer(response_buffer));

        // Print response. Since the response can be shorter than the buffer, we trim using substr()
        cout << "Response: " << response_buffer.substr(0,length) << endl;
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}


