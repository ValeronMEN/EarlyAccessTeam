#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

using namespace std;
using namespace cv;


String window_name = "Capture - Face detection";

void detectAndDisplay( Mat frame );

int main( void )
{
	// for updating
    VideoCapture capture;
    capture.open(0);
    Mat frame;
    if ( ! capture.isOpened() )
    {
        return -1;
    }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            break;
        }
        int c = waitKey(10);
        imshow( window_name, frame );
        if( (char)c == 27 )
        {
            break;
        }
    }
    return 0;
}

void detectAndDisplay( Mat frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(70, 70) );
    for( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 0, 13, 26), 4, 8, 0 );
    }
    std::cout« "Face index" « i « ": x-" « faces[i].x + faces[i].width/2 « ", y-" « faces[i].y + faces[i].height/2 « endl;
    imshow( window_name, frame );
}

