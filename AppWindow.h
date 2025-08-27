#ifndef APPWINDOW_H
#define APPWINDOW_H


#include <QMainWindow>


class BrowserPane;
class ISizeMapper;


class AppWindow : public QMainWindow
{
    Q_OBJECT
private:
    BrowserPane* pane;
    ISizeMapper* dirMapper;
    ISizeMapper* typeMapper;
public:
    explicit AppWindow(QWidget* parent = nullptr);
};


#endif // APPWINDOW_H
