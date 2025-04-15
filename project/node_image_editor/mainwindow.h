// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };
// #endif // MAINWINDOW_H


#pragma once
#include <QMainWindow>
#include <QGraphicsView>
#include <QFormLayout>
#include <QLabel>
#include "NodeGraph.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
public slots:
    void onRunPipeline();
    void onNodeSelected(Node *node);
private slots:
    void onAddNode();
    void onOpenImage();
    void onSaveImage();
private:
    NodeGraph   *graph_;
    QGraphicsView *view_;
    QWidget     *propPanel_;
    QFormLayout *propLayout_;
    QLabel      *previewLabel_;
};
