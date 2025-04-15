// #include "mainwindow.h"
// #include "ui_mainwindow.h"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }


#include "MainWindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QSplitter>
#include <QInputDialog>
#include <QToolBar>
#include <QStatusBar>
#include "nodes/InputNode.h"
#include "nodes/OutputNode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // File menu
    auto *fm = menuBar()->addMenu("File");
    fm->addAction("Open…", this, &MainWindow::onOpenImage);
    fm->addAction("Save…", this, &MainWindow::onSaveImage);

    // Canvas & properties
    auto *split = new QSplitter;
    view_ = new QGraphicsView(split);
    graph_ = new NodeGraph(view_->scene(), this);
    view_->setScene(graph_->scene());
    propPanel_ = new QWidget(split);
    propLayout_ = new QFormLayout(propPanel_);
    split->addWidget(propPanel_);
    setCentralWidget(split);

    // Toolbars
    addToolBar("Nodes")->addAction("Add Node", this, &MainWindow::onAddNode);
    addToolBar("Run")->addAction("Run", this, &MainWindow::onRunPipeline);

    // Preview
    previewLabel_ = new QLabel;
    statusBar()->addPermanentWidget(previewLabel_);
}

void MainWindow::onAddNode() {
    QStringList types = { "Input", "Output" };
    bool ok;
    QString t = QInputDialog::getItem(this, "Add Node", "Type:", types, 0, false, &ok);
    if (!ok) return;
    graph_->addNodeByType(t);
}

void MainWindow::onRunPipeline() {
    graph_->execute();
    auto img = graph_->getFinalImage();
    if (!img.empty()) {
        QImage q(img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
        previewLabel_->setPixmap(QPixmap::fromImage(q).scaled(160,120,Qt::KeepAspectRatio));
    }
}

void MainWindow::onOpenImage() {
    QString f = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (!f.isEmpty()) graph_->setInputPath(f.toStdString());
}

void MainWindow::onSaveImage() {
    QString f = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG (*.png);;JPG (*.jpg)");
    if (!f.isEmpty()) graph_->saveResult(f.toStdString());
}

void MainWindow::onNodeSelected(Node *node) {
    // clear old
    QLayoutItem *it;
    while ((it = propLayout_->takeAt(0))) {
        delete it->widget();
        delete it;
    }
    node->model()->populateProperties(propLayout_);
}
