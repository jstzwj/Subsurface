#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMenu>
#include "viewwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    // widget
    QWidget * windowCentralWidget;
    QVBoxLayout * vLayout;
    ViewWidget * viewWorkspace;

    // menu
    QMenu * menu_edit;
    QMenu * menu_tools;
    QMenu * menu_group;
    QMenu * menu_views;
    QMenu * menu_create;
    QMenu * menu_modifiers;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
