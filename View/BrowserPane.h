#ifndef BROWSERPANE_H
#define BROWSERPANE_H


#include <QWidget>
#include <QMenuBar>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QStackedWidget>
#include <QAction>
#include <QVBoxLayout>
#include "../Observer/IObserver.h"
#include "../Strategies/ISizeMapper.h"


class TableView;
class BarChartView;
class PieChartView;


class BrowserPane : public QWidget, public IObserver
{
    Q_OBJECT
private:
    QString rootDirPath;
    QFileSystemModel* fsModel;
    QTreeView* fsView;
    QStackedWidget* rightStack;
    QMenuBar* menu;
    QMenu* groupMenu;
    QMenu* chartMenu;
    QMap<QString, ISizeMapper*> strategies;
    ISizeMapper* currentMapper = nullptr;
public:
    explicit BrowserPane(QWidget* parent = nullptr);
    void addStrategy(const QString& name, ISizeMapper* mapper);
    void updateDisplay(const QMap<QString, quint64>& sizesMap) override;
private slots:
    void onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected);
    void showTable();
    void showBar();
    void showPie();
};


#endif // BROWSERPANE_H
