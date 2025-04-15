#include "Node.h"
#include "MainWindow.h"

Node::Node(NodeModel *m): QGraphicsRectItem(0,0,120,50), m_(m) {
    setFlag(ItemIsSelectable);
    setBrush(QColor(200,200,200));
}

Node::~Node(){ delete m_; }

void Node::mousePressEvent(QGraphicsSceneMouseEvent *e) {
    QGraphicsRectItem::mousePressEvent(e);
    if (isSelected()) {
        auto mw = dynamic_cast<MainWindow*>(parent());
        if (mw) mw->onNodeSelected(this);
    }
}
