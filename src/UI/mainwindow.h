#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>
#include <QDockWidget>
#include "viewwidget.h"
#include "customedtitlebar.h"
#include "commandpanel.h"

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
    // title bar
    CustomedTitleBar *pTitleBar;

    // menubar
    QMenuBar *menubar;

    // widget
    QWidget * windowCentralWidget;
    QMainWindow * mainDockArea;
    QVBoxLayout * mainVLayout;
    QVBoxLayout * vLayout;
    ViewWidget * viewWorkspace;

    // menu
    QMenu * menu_edit;
    QMenu * menu_tools;
    QMenu * menu_group;
    QMenu * menu_views;
    QMenu * menu_create;
    QMenu * menu_modifiers;

    // dock
    QDockWidget * viewDock;
    QDockWidget * commandDock;

    // panel
    CommandPanel * commandPanel;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
