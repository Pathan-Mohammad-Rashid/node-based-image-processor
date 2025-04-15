#pragma once
#include <QGraphicsScene>
#include <vector>
#include <opencv2/opencv.hpp>
class MainWindow; class Node;
class NodeGraph {
public:
    NodeGraph(QGraphicsScene*, MainWindow*);
    QGraphicsScene* scene() const;
    void addNodeByType(const QString&);
    void execute();
    cv::Mat getFinalImage() const;
    void setInputPath(const std::string&);
    void saveResult(const std::string&);
private:
    MainWindow *win_;
    QGraphicsScene *scene_;
    std::vector<Node*> nodes_;
    std::string inputPath_;
    cv::Mat lastOut_;
};
