#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <conio.h>
#include <iostream>
#include "SerialClass.h"

#define TOP_BORDER 160
#define BOTTOM_BORDER 250
#define LEFT_BORDER 250
#define RIGHT_BORDER 220

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );

String face_cascade_name = "haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

String window_name = "Spy Cam! Behrang - sexy gay";

Serial* SP;
char* buffer;

bool done;
int command;


int main( void )
{
    done = false;
    SP = new Serial("\\\\.\\COM8");
    if (SP->IsConnected())
		printf("Connected");
    buffer="0";
    SP->WriteData(buffer, 1);
    command = 0;
    Sleep(500);
    //
    VideoCapture capture;
    capture.open(0);
    Mat frame;
    if( !face_cascade.load( face_cascade_name ) )
    {
        printf("--(!)Error loading face cascade\n");
        return -1;
    };
    if( !eyes_cascade.load( eyes_cascade_name ) )
    {
        printf("--(!)Error loading eyes cascade\n");
        return -1;
    };
    if ( ! capture.isOpened() )
    {
        printf("--(!)Error opening video capture\n");
        return -1;
    }
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" —(!) No captured frame — Break!");
            break;
        }
        detectAndDisplay( frame );
        int c = waitKey(10);
        if( (char)c == 27 )
        {
            break;
        }
    }

    return 0;
}
