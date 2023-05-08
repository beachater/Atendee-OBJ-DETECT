#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;
using namespace dnn;

int main()
{
    // Initialize the video capture object.
    VideoCapture cap("E:\\OBJDETECT using\\DNN_YOLOV3\\x64\\video1.mp4");

    // Check if the video capture object is opened.
    if (!cap.isOpened()) {
        cout << "Video Capture Fail" << endl;
        return -1;
    }

    // Load the YOLOv3 model.
    Net network = readNet("E:\\OBJDETECT using\\DNN_YOLOV3\\x64\\yolov3-tiny.weights", "E:\\OBJDETECT using\\DNN_YOLOV3\\x64\\yolov3-tiny.cfg.txt", "Darknet");

    // Set the preferred backend and target.
    network.setPreferableBackend(DNN_BACKEND_DEFAULT);
    network.setPreferableTarget(DNN_TARGET_OPENCL);

    // Create a window for display.
    namedWindow("Display window", WINDOW_AUTOSIZE);

    // Loop over the frames of the video.
    for (;;) {
        // Get the next frame from the video capture object.
        Mat img;
        cap >> img;

        // Check if the frame is empty.
        if (img.empty()) {
            break;
        }

        // Convert the image to a blob.
        Mat blobFromImg;
        bool swapRB = true;
        blobFromImage(img, blobFromImg, 1, Size(416, 416), Scalar(), swapRB, false);

        // Set the input of the network.
        network.setInput(blobFromImg, "", 1.0 / 255.0, Scalar(0));

        // Forward the network.
        Mat outMat;
        network.forward(outMat);

        // Get the number of detected objects.
        int rowsNoOfDetection = outMat.rows;

        // Loop over the detected objects.
        for (int j = 0; j < rowsNoOfDetection; ++j) {
            // Get the coordinates of the bounding box.
            int centerX = (int)(outMat.at<float>(j, 0) * img.cols);
            int centerY = (int)(outMat.at<float>(j, 1) * img.rows);
            int width = (int)(outMat.at<float>(j, 2) * img.cols + 20);
            int height = (int)(outMat.at<float>(j, 3) * img.rows + 100);

            // Get the confidence of the detection.
            double confidence = outMat.at<float>(j, 4);

            // Draw the bounding box and the confidence on the image.
            if (confidence > 0.5) {
                rectangle(img, Rect(centerX - width / 2, centerY - height / 2, width, height), Scalar(0, 255, 0), 2, 8, 0);
            }
        }

        // Display the image.
        imshow("Display window", img);

        // Wait for a key press.
        waitKey(25);
    }

    // Close the window.
    destroyWindow("Display window");

    // Return 0.
    return 0;
}
