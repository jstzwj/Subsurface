#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // layout
    windowCentralWidget = new QWidget(this);
    vLayout = new QVBoxLayout(windowCentralWidget);

    // titlebar
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    pTitleBar = new CustomedTitleBar(windowCentralWidget);
    installEventFilter(pTitleBar);

    setWindowTitle("Subsurface");
    setWindowIcon(QIcon(":/rsc/images/logo/logo.png"));

    // menu
    menu_edit = new QMenu(tr("Edit"));
    menu_edit->addAction(tr("New"));
    menu_edit->addAction(tr("Reset"));
    menu_edit->addAction(tr("Open"));
    menu_edit->addAction(tr("Save"));
    menu_edit->addAction(tr("Save As"));

    menu_tools =new QMenu(tr("Tools"));
    menu_tools->addAction(tr("Undo or Redo"));

    menubar = new QMenuBar(windowCentralWidget);
    menubar->setFixedHeight(40);
    menubar->addMenu(menu_edit);
    menubar->addMenu(menu_tools);

    // dock
    mainDockArea = new QMainWindow(this);
    viewDock = new QDockWidget(mainDockArea);
    commandDock = new QDockWidget(mainDockArea);

    // panel
    commandPanel = new CommandPanel(commandDock);
    viewWorkspace = new ViewWidget(viewDock);

    viewDock->setWidget(viewWorkspace);
    viewDock->setFeatures(QDockWidget::DockWidgetClosable);
    viewDock->setWindowTitle("View Panel");

    commandDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    commandDock->setWidget(commandPanel);
    commandDock->setWindowTitle("Command Panel");


    mainDockArea->addDockWidget(Qt::RightDockWidgetArea, commandDock);
    mainDockArea->setCentralWidget(viewDock);

    vLayout->setMargin(0);
    vLayout->addWidget(pTitleBar);
    vLayout->addWidget(menubar);
    vLayout->addWidget(mainDockArea);

    windowCentralWidget->setLayout(vLayout);
    this->setCentralWidget(windowCentralWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}
