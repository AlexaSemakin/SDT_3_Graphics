#ifndef TABLEVIEW_H
#define TABLEVIEW_H


#include <QWidget>
#include <QVBoxLayout>
#include <QTableView>
#include "../Models/FileBrowserModel.h"


class TableView : public QWidget
{
    Q_OBJECT
private:
    FileBrowserModel* model;
    QTableView* view;
public:
    explicit TableView(QWidget* parent = nullptr);
    void setData(const QMap<QString, quint64>& sizesMap);
};


#endif // TABLEVIEW_H
