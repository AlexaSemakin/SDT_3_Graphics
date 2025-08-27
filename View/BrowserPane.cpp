#include "BrowserPane.h"
#include "TableView.h"
#include "BarChartView.h"
#include "PieChartView.h"

#include <QHeaderView>
#include <QDir>

BrowserPane::BrowserPane(QWidget* parent) : QWidget(parent)
{
    rootDirPath = QDir::homePath();

    menu = new QMenuBar(this);
    groupMenu = new QMenu("Group", menu);
    chartMenu = new QMenu("Chart", menu);
    menu->addMenu(groupMenu);
    menu->addMenu(chartMenu);

    menu->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    auto *splitter = new QSplitter(this);

    fsModel = new QFileSystemModel(this);
    fsModel->setRootPath(rootDirPath);
    fsModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    fsView = new QTreeView();
    fsView->setModel(fsModel);
    fsView->setRootIndex(fsModel->index(rootDirPath));
    fsView->expandToDepth(1);
    fsView->header()->hideSection(1);
    fsView->header()->hideSection(2);
    fsView->header()->hideSection(3);

    rightStack = new QStackedWidget();
    rightStack->addWidget(new TableView(this));
    rightStack->addWidget(new BarChartView(this));
    rightStack->addWidget(new PieChartView(this));

    splitter->addWidget(fsView);
    splitter->addWidget(rightStack);

    splitter->setSizes(QList<int>{ 350, 750 });

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(menu);
    layout->addWidget(splitter);

    auto *tableAction = new QAction("Table", this);
    auto *barAction   = new QAction("Bar", this);
    auto *pieAction   = new QAction("Pie", this);
    chartMenu->addAction(tableAction);
    chartMenu->addAction(barAction);
    chartMenu->addAction(pieAction);

    connect(tableAction, &QAction::triggered, this, &BrowserPane::showTable);
    connect(barAction,   &QAction::triggered, this, &BrowserPane::showBar);
    connect(pieAction,   &QAction::triggered, this, &BrowserPane::showPie);

    connect(fsView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &BrowserPane::onSelectionChanged);
}

void BrowserPane::addStrategy(const QString& name, ISizeMapper* mapper)
{
    if (strategies.contains(name)) return;
    strategies.insert(name, mapper);
    mapper->addObserver(this);

    auto *action = new QAction(name, this);
    connect(action, &QAction::triggered, this, [this, name]() {
        currentMapper = strategies.value(name);
        currentMapper->getSizesMap(rootDirPath);
    });
    groupMenu->addAction(action);
}

void BrowserPane::updateDisplay(const QMap<QString, quint64>& sizesMap)
{
    auto *table = qobject_cast<TableView*>(rightStack->widget(0));
    auto *bar   = qobject_cast<BarChartView*>(rightStack->widget(1));
    auto *pie   = qobject_cast<PieChartView*>(rightStack->widget(2));

    table->setData(sizesMap);
    bar->setData(sizesMap);
    pie->setData(sizesMap);
}

void BrowserPane::onSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    Q_UNUSED(deselected)
    if (!selected.indexes().isEmpty()) {
        rootDirPath = fsModel->filePath(selected.indexes().first());
        if (currentMapper) currentMapper->getSizesMap(rootDirPath);
    }
}

void BrowserPane::showTable() { rightStack->setCurrentIndex(0); }
void BrowserPane::showBar()   { rightStack->setCurrentIndex(1); }
void BrowserPane::showPie()   { rightStack->setCurrentIndex(2); }
