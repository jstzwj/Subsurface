#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // menu
    menu_edit = new QMenu("Edit");



    ui->menuBar->addMenu(menu_edit);

    // layout
    windowCentralWidget = new QWidget();
    vLayout = new QVBoxLayout();
    viewWorkspace = new ViewWidget();

    vLayout->addWidget(viewWorkspace);
    windowCentralWidget->setLayout(vLayout);
    this->setCentralWidget(windowCentralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
