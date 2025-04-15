// InputNode.h
#pragma once
#include "../NodeModel.h"
#include <QLabel>

class QPushButton;
class InputNode : public NodeModel {
    Q_OBJECT
public:
    InputNode(MainWindow *w);
    cv::Mat process(const std::vector<cv::Mat>&) override;
    void populateProperties(QFormLayout*) override;
private slots:
    void onBrowse();
private:
    QString path_;
    QLabel *info_;
};
