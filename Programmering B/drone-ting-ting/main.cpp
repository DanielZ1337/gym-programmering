#include <iostream>
#include "asio.hpp"
#include "include_opencv.h"
#include <string>
#include <stdexcept>
#include <thread>
#include <atomic>

using namespace std;
using asio::ip::udp;

// Target IP address and port
const asio::ip::address IP = asio::ip::make_address("192.168.10.1");
const short PORT = 8889;
std::atomic<char> k{-1};

void sendCommand()
{
    // Setup io_context that will handle input/output
    asio::io_context io_context;

    // Socket to send and receive the messages (using ip v4)
    udp::socket socket(io_context,udp::v4());

    // Remote endpoint with ip and port
    udp::endpoint endpoint(IP,PORT);

    socket.send_to(asio::buffer("command"), endpoint);
    socket.send_to(asio::buffer("streamon"), endpoint);

    // Use socket to send message to remote endpoint
    while(1)
    {
        if(k > -1)
        {
            switch(k)
            {
            case 'w':
                cout << "W pressed" << endl;
                socket.send_to(asio::buffer("rc 0 100 0 0"), endpoint);
                break;

            case 's':
                cout << "S pressed" << endl;
                socket.send_to(asio::buffer("rc 0 -70 0 0"), endpoint);
                break;

            case 'a':
                cout << "A pressed" << endl;
                socket.send_to(asio::buffer("rc -70 0 0 0"), endpoint);
                break;

            case 'd':
                cout << "D pressed" << endl;
                socket.send_to(asio::buffer("rc 70 0 0 0"), endpoint);
                break;

            case 't':
                cout << "T pressed" <<  endl;
                socket.send_to(asio::buffer("takeoff"), endpoint);
                break;

            case 'y':
                cout << "Y pressed" << endl;
                socket.send_to(asio::buffer("land"), endpoint);
                break;

            case 'u':
                cout << "U pressed" << endl;
                socket.send_to(asio::buffer("rc 0 0 50 0"), endpoint);
                break;

            case 'i':
                cout << "I pressed" << endl;
                socket.send_to(asio::buffer("rc 0 0 -50 0"), endpoint);
                break;

            case 'f':
                cout << "F pressed" << endl;
                socket.send_to(asio::buffer("flip b"), endpoint);
                break;

            case '+':
                cout << "+ pressed" << endl;
                socket.send_to(asio::buffer("emergency"), endpoint);
                break;

            case 'q':
                cout << "Q was pressed" << endl;
                socket.send_to(asio::buffer("rc 0 0 0 -70"), endpoint);
                break;

            case 'e':
                cout << "E was pressed" << endl;
                socket.send_to(asio::buffer("rc 0 0 0 70"), endpoint);
                break;

            case 'x':
                socket.send_to(asio::buffer("rc 0 0 0 0"), endpoint);
                break;
            }

               k = -1;
//            // Use socket to receive response
            string response_buffer(1000,' ');
            //size_t length = socket.receive(asio::buffer(response_buffer));

            // Print response. Since the response can be shorter than the buffer, we trim using substr()
            //cout << "Response: " << response_buffer.substr(0,length) << endl;
        }
    }
}

void video_stream()
{
    std::thread command(sendCommand);
    cv::VideoCapture vid("udp://192.168.10.1:11111");

    // Check if we can open video
    if (vid.isOpened())
    {
        cout << "Ready to use " << vid.get(cv::CAP_PROP_FRAME_WIDTH) << "x" << vid.get(cv::CAP_PROP_FRAME_HEIGHT) << " video." << endl;
    }
    else
    {
        throw runtime_error("Could not open video!");
    }

    // Create a window
    string wname = "Video frame.";
    cv::namedWindow(wname, cv::WINDOW_AUTOSIZE);

    // Create empty frame object
    cv::Mat frame;

    while(true)
    {
        // Wait for keypress before exit
        k = cv::waitKey(1000/60);


        vid >> frame;

        // Show frame
        cv::imshow(wname,frame);
    }
    command.join();
}




void retrieveCommand()
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

int main()
{
    // Basic asio check
    cout << "Press T to start flying and Y to land" << endl;
    cout << "Press W and S to fly forward and backwards" << endl;
    cout << "Press A and D to fly from side to side" << endl;
    cout << "Press Q and E to yaw" << endl;
    cout << "Press U and I to change altitude" << endl;
    cout << "Press F to do a flip" << endl;
    cout << "Press X to stop actions" << endl;
    cout << endl;

    asio::io_context io;
    if(io.stopped())
        cout << "ASIO io_context stopped." << endl;
    else
        cout << "ASIO io_context is running." << endl;

    // Basic OpenCV check
    cout << "openCV version: " << CV_VERSION << endl;



    video_stream();


    return 0;
}


