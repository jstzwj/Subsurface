#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // titlebar
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    pTitleBar = new CustomedTitleBar(this);
    installEventFilter(pTitleBar);

    setWindowTitle("Subsurface");
    setWindowIcon(QIcon(":/rsc/images/logo/logo.png"));

    // menu
    menu_edit = new QMenu("Edit");
    menu_edit->addAction("New");
    menu_edit->addAction("Reset");

    menu_tools =new QMenu("Tools");

    menubar = new QMenuBar();
    menubar->setFixedHeight(40);
    menubar->addMenu(menu_edit);
    menubar->addMenu(menu_tools);

    // panel
    commandPanel = new CommandPanel();

    // layout
    windowCentralWidget = new QWidget();
    vLayout = new QVBoxLayout();
    viewWorkspace = new ViewWidget();

    // dock
    mainDockArea = new QMainWindow();
    viewDock = new QDockWidget();
    commandDock = new QDockWidget();

    viewDock->setWidget(viewWorkspace);
    viewDock->setFeatures(QDockWidget::DockWidgetClosable);
    viewDock->setWindowTitle("View Panel");

    commandDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    commandDock->setWidget(commandPanel);
    commandDock->setWindowTitle("Command Panel");

    vLayout->setMargin(0);
    vLayout->addWidget(pTitleBar);
    vLayout->addWidget(menubar);
    vLayout->addWidget(mainDockArea);
    mainDockArea->addDockWidget(Qt::RightDockWidgetArea, commandDock);
    mainDockArea->setCentralWidget(viewDock);

    windowCentralWidget->setLayout(vLayout);
    this->setCentralWidget(windowCentralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
