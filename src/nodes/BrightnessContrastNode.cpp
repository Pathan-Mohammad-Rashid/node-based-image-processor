// BrightnessContrastNode.cpp
#include "BrightnessContrastNode.h"
#include <QSlider>
#include <QPushButton>
#include <QLabel>

BrightnessContrastNode::BrightnessContrastNode(MainWindow *w)
    : NodeModel(w), brightness_(0), contrast_(1.0),
      sB_(nullptr), sC_(nullptr) {}

cv::Mat BrightnessContrastNode::process(const std::vector<cv::Mat> &inputs)
{
    if (inputs.empty())
        return {};
    cv::Mat out;
    inputs[0].convertTo(out, -1, contrast_, brightness_);
    return out;
}

void BrightnessContrastNode::populateProperties(QFormLayout *f)
{
    sB_ = new QSlider(Qt::Horizontal);
    sB_->setRange(-100, 100);
    sB_->setValue(brightness_);
    sC_ = new QSlider(Qt::Horizontal);
    sC_->setRange(0, 300);
    sC_->setValue(int(contrast_ * 100));
    auto *rB = new QPushButton("Reset B");
    auto *rC = new QPushButton("Reset C");
    f->addRow("Brightness", sB_);
    f->addRow("", rB);
    f->addRow("Contrast", sC_);
    f->addRow("", rC);
    connect(sB_, &QSlider::valueChanged, this, &BrightnessContrastNode::onParamsChanged);
    connect(sC_, &QSlider::valueChanged, this, &BrightnessContrastNode::onParamsChanged);
    connect(rB, &QPushButton::clicked, this, &BrightnessContrastNode::onResetB);
    connect(rC, &QPushButton::clicked, this, &BrightnessContrastNode::onResetC);
}

void BrightnessContrastNode::onParamsChanged()
{
    brightness_ = sB_->value();
    contrast_ = sC_->value() / 100.0;
    win_->onRunPipeline();
}

void BrightnessContrastNode::onResetB()
{
    sB_->setValue(0);
}
void BrightnessContrastNode::onResetC()
{
    sC_->setValue(100);
}
