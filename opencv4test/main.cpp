
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;
int main()
{
    cv::Mat image2(128, 128, CV_8UC3);

    auto image = imread( "green3.png", IMREAD_COLOR ); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.


      int xx=0,yy=0;
    while (bool running = true) {
        xx=(xx+33) % 128;
        yy=(yy+33) % 128;
        for(int x=0;x<=127;x++){
            for(int y=0;y<=127;y++){
                image2.at<cv::Vec3b>(x, y) = image.at<cv::Vec3b>(x + xx, y);
                usleep(1000);
            }
        }
        imshow( "Display window", image2 );                // Show our image inside it.
                
    }
    
        std::cout << waitKey(33) << std::endl;

    return 0; // Wait for a keystroke in the window
}
