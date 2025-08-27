#include "TableView.h"


TableView::TableView(QWidget* parent) : QWidget(parent)
{
    model = new FileBrowserModel(this);
    view = new QTableView(this);
    view->setModel(model);


    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(view);
}


void TableView::setData(const QMap<QString, quint64>& sizesMap)
{
    model->setData(sizesMap);
}
