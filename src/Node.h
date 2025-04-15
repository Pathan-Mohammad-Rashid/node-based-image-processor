#pragma once
#include <QGraphicsRectItem>
#include "NodeModel.h"

class Node : public QGraphicsRectItem {
public:
    Node(NodeModel *m);
    ~Node();
    NodeModel* model() const { return m_; }
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
private:
    NodeModel *m_;
};
