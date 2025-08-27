#include "AppWindow.h"
#include "View/BrowserPane.h"
#include "Strategies/DirSizeMapper.h"
#include "Strategies/TypeSizeMapper.h"


AppWindow::AppWindow(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Dashboard");
    resize(1100, 650);


    pane = new BrowserPane(this);
    setCentralWidget(pane);


    dirMapper = new DirSizeMapper;
    typeMapper = new TypeSizeMapper;


    pane->addStrategy("Group by dir", dirMapper);
    pane->addStrategy("Group by type", typeMapper);
}
