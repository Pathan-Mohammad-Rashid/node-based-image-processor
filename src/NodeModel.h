#pragma once
#include <QObject>
#include <QFormLayout>
#include <opencv2/opencv.hpp>
#include "MainWindow.h"

class NodeModel : public QObject {
    Q_OBJECT
public:
    NodeModel(MainWindow *w): QObject(w), win_(w){}
    virtual ~NodeModel(){}
    virtual cv::Mat process(const std::vector<cv::Mat>&)=0;
    virtual void populateProperties(QFormLayout*)=0;
protected:
    MainWindow *win_;
};
