#include "HAAR.h"
#include "ui_HAAR.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


HAAR::HAAR(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // Connect the button click signal to the corresponding slot
    connect(ui.cntButton, &QPushButton::clicked, this, &HAAR::on_cntButton_clicked);

}

HAAR::~HAAR()
{
}

void HAAR::on_cntButton_clicked()
{
    int count = 0;
    bool stop = false;

    cv::VideoCapture vid("E:\\OBJDETECT using\\HAAR\\slow2.mp4"); // Replace "image_name" with the correct video file path
    cv::Mat frame;
    detectAndDisplay(frame, count, vid, stop);

    //// Update the count display
    //ui.COUNTER->display(count);

    //// Convert the OpenCV image to a QImage
    //QImage qImage(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888);

    //// Create a QGraphicsPixmapItem with the image
    //QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(qImage));

    //// Create a QGraphicsScene and add the pixmap item to the scene
    //QGraphicsScene* scene = new QGraphicsScene(this);
    //scene->addItem(pixmapItem);

    //// Set the scene on the QGraphicsView
    //ui.DISPLAY->setScene(scene);
}




void HAAR::detectAndDisplay(cv::Mat frame, int& count, cv::VideoCapture& vid, bool& stop)
{
    std::string body_cascade_name = "E:\\OBJDETECT using\\HAAR\\haarcascade_fullbody.xml";
    if (!body_cascade.load(body_cascade_name))
    {
        std::cout << "--(!)Error loading body cascade\n";
        return;
    }
    double fps = vid.get(cv::CAP_PROP_FPS);
    int interval = 10; // read a frame every 10 seconds
    int intervalFrames = static_cast<int>(fps * interval);
    int frameCount = 0;

    while (!stop)
    {
        // read the next frame
        vid.read(frame);

        if (frame.empty()) // exit if no more frames
            break;

        frameCount++;

        if (frameCount % intervalFrames == 0) // process every `interval` seconds
        {
            cv::resize(frame, frame, cv::Size(416, 416));
            cv::Mat frame_gray;
            cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
            cv::equalizeHist(frame_gray, frame_gray);

            //-- Detect bodies
            std::vector<cv::Rect> bodies;
            body_cascade.detectMultiScale(frame_gray, bodies);

            count = 0;

            for (size_t i = 0; i < bodies.size(); i++)
            {
                cv::rectangle(frame, bodies[i], cv::Scalar(0, 255, 0), 2);
                count++;
            }

            //-- Resize the frame to fit on screen
            cv::resize(frame, frame, cv::Size(800, 600));

            //-- Convert the OpenCV image to a QImage
            QImage qImage(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888);

            //-- Create a QPixmap from the QImage
            QPixmap pixmap = QPixmap::fromImage(qImage);

            //-- Set the pixmap as the image in the QGraphicsPixmapItem
            QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap);

            //-- Create a QGraphicsScene and add the pixmap item to the scene
            QGraphicsScene* scene = new QGraphicsScene(this);
            scene->addItem(pixmapItem);

            //-- Set the scene on the QGraphicsView
            ui.DISPLAY->setScene(scene);

            //-- Update the count display
            ui.COUNTER->display(count);
        }

        if (cv::waitKey(5) == 27) // Press Esc to stop
            stop = true;
    }
}

