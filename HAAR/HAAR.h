#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HAAR.h"
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
class QGraphicsScene; // Forward declaration
class QGraphicsPixmapItem; // Forward declaration
class HAAR : public QMainWindow
{
    Q_OBJECT

public:
    HAAR(QWidget* parent = nullptr);
    ~HAAR();

private slots:
    void on_cntButton_clicked(); // Slot connected to the button click

private:
    Ui::HAARClass ui;

    cv::CascadeClassifier body_cascade; // Declare CascadeClassifier as a member variable

    void detectAndDisplay(cv::Mat frame, int& count, cv::VideoCapture& vid, bool& stop);
};
