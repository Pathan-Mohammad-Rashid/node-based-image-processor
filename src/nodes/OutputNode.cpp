// OutputNode.cpp
#include "OutputNode.h"
#include <QPushButton>
#include <QFileDialog>

OutputNode::OutputNode(MainWindow *w): NodeModel(w), info_(nullptr) {}

cv::Mat OutputNode::process(const std::vector<cv::Mat>& in) {
    return in.empty() ? cv::Mat() : in[0];
}

void OutputNode::populateProperties(QFormLayout *f) {
    auto *btn = new QPushButton("Browse…");
    info_ = new QLabel("No output");
    f->addRow("Save to:", btn);
    f->addRow("Info:", info_);
    connect(btn,&QPushButton::clicked,this,&OutputNode::onBrowse);
}

void OutputNode::onBrowse() {
    QString f = QFileDialog::getSaveFileName(nullptr,"Save Image","","PNG (*.png);;JPG (*.jpg)");
    if (f.isEmpty()) return;
    info_->setText(f.section('/',-1));
    // actual save happens via MainWindow→Save
}
