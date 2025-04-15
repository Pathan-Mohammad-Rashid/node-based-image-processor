// BrightnessContrastNode.h
#pragma once
#include "../NodeModel.h"
class QSlider;
class QPushButton;
class BrightnessContrastNode : public NodeModel
{
    Q_OBJECT
public:
    BrightnessContrastNode(MainWindow *w);
    cv::Mat process(const std::vector<cv::Mat> &inputs) override;
    void populateProperties(QFormLayout *form) override;
private slots:
    void onParamsChanged();
    void onResetB();
    void onResetC();

private:
    int brightness_;  // –100…+100
    double contrast_; // 0…3
    QSlider *sB_, *sC_;
};
