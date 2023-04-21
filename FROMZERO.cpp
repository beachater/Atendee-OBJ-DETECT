#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame, int &count);

CascadeClassifier body_cascade;

int main(int argc, const char** argv)
{
    CommandLineParser parser(argc, argv,
        "{help h||}"
        "{body_cascade|D:\\Resources\\data\\haarcascades\\haarcascade_fullbody.xml|Path to body cascade.}"
        "{image|D:\\Resources\\00pedxing01.jpg|Path to input image.}");

    parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect full bodies in an image using Haar or LBP features.\n\n");
    parser.printMessage();
    int count = 0;

    String body_cascade_name = parser.get<String>("body_cascade");
    String image_name = parser.get<String>("image");

    //-- 1. Load the cascade
    if (!body_cascade.load(body_cascade_name))
    {
        cout << "--(!)Error loading body cascade\n";
        return -1;
    };

    Mat frame = imread(image_name);
    if (frame.empty())
    {
        cout << "--(!)Error reading image\n";
        return -1;
    }
    
    detectAndDisplay(frame, count);
    cout << "COUNT IS " << count;

    waitKey(0);

    return 0;
}

void detectAndDisplay(Mat frame, int &count)
{
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    //-- Detect bodies
    std::vector<Rect> bodies;
    body_cascade.detectMultiScale(frame_gray, bodies);
    
 
    for (size_t i = 0; i < bodies.size(); i++)
    {
        rectangle(frame, bodies[i], Scalar(0, 255, 0), 2);
        count++;
    }

    //-- Resize the frame to fit on screen
    resize(frame, frame, Size(800, 600));

    //-- Show what you got
    imshow("Body detection", frame);
}
