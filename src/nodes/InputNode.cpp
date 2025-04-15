// InputNode.cpp
#include "InputNode.h"
#include <QPushButton>
#include <QFileDialog>

InputNode::InputNode(MainWindow *w): NodeModel(w), info_(nullptr) {}

cv::Mat InputNode::process(const std::vector<cv::Mat>&) {
    return cv::imread(path_.toStdString());
}

void InputNode::populateProperties(QFormLayout *f) {
    auto *btn = new QPushButton("Browse…");
    info_ = new QLabel("No file");
    f->addRow("Image:", btn);
    f->addRow("Info:", info_);
    connect(btn,&QPushButton::clicked,this,&InputNode::onBrowse);
}

void InputNode::onBrowse() {
    QString f = QFileDialog::getOpenFileName(nullptr,"Select Image","","Images (*.png *.jpg *.bmp)");
    if (f.isEmpty()) return;
    path_ = f;
    info_->setText(f.section('/',-1));
    win_->onRunPipeline();
}
