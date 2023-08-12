//
// local_video.cpp
// ~~~~~~~~~~
//
// Open local video file and display a single frame
//

#include "include_opencv.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main()
{
    // Path might need to be adjusted to absolute path to video file
    cv::VideoCapture vid("media/Megamind.avi");

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

    // Skip 2 milliseconds and read frame
    vid.set(cv::CAP_PROP_POS_MSEC,2000);
    vid >> frame;

    if (frame.empty())
    {
        cout << "Empty frame";
        return 0;
    }

    // Show frame
    cv::imshow(wname,frame);

    // Wait for keypress before exit
    cv::waitKey();

    return 0;
}
