// OutputNode.h
#pragma once
#include "../NodeModel.h"
#include <QLabel>

class QPushButton;
class OutputNode : public NodeModel {
    Q_OBJECT
public:
    OutputNode(MainWindow *w);
    cv::Mat process(const std::vector<cv::Mat>&) override;
    void populateProperties(QFormLayout*) override;
private slots:
    void onBrowse();
private:
    QLabel *info_;
};
