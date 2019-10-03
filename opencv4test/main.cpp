#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;
int main()
{
  
    cv::Mat image(128, 128, CV_8UC3);
    cv::Mat image2(128, 128, CV_8UC3);
    image = imread( "/green3.png", IMREAD_COLOR ); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.

    int x=0,y=0,xx=0,yy=0;
    for(x=0;x<=127;x++){
    //    for(y=0;y<=127;y++){
            xx=x+1;
            yy=y+1;
            image2.at<cv::Vec3b>(x, y) = image.at<cv::Vec3b>(xx, y);
            imshow( "Display window", image2 );                // Show our image inside it.
            usleep(1000);
        //if (x==127){x=0;};
    //    }
       
    }
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
