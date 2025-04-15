#include "NodeGraph.h"
#include "Node.h"
#include "nodes/InputNode.h"
#include "nodes/OutputNode.h"
#include <opencv2/imgcodecs.hpp>

NodeGraph::NodeGraph(QGraphicsScene *s, MainWindow *w)
    : scene_(s), win_(w) {}

QGraphicsScene* NodeGraph::scene() const { return scene_; }

void NodeGraph::addNodeByType(const QString &t) {
    NodeModel *m = nullptr;
    if (t=="Input")  m = new InputNode(win_);
    if (t=="Output") m = new OutputNode(win_);
    if (!m) return;
    auto *n = new Node(m);
    scene_->addItem(n);
    nodes_.push_back(n);
}

void NodeGraph::execute() {
    cv::Mat data;
    for (auto *n : nodes_) {
        if (dynamic_cast<InputNode*>(n->model()))
            data = n->model()->process({});
        else
            data = n->model()->process({data});
    }
    lastOut_ = data;
}

cv::Mat NodeGraph::getFinalImage() const { return lastOut_; }

void NodeGraph::setInputPath(const std::string &p) { inputPath_ = p; }

void NodeGraph::saveResult(const std::string &p) {
    if (!lastOut_.empty()) cv::imwrite(p, lastOut_);
}
