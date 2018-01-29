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

    // layout
    windowCentralWidget = new QWidget();
    vLayout = new QVBoxLayout();
    viewWorkspace = new ViewWidget();

    vLayout->setMargin(0);
    vLayout->addWidget(pTitleBar);
    vLayout->addWidget(menubar);
    vLayout->addWidget(viewWorkspace);

    windowCentralWidget->setLayout(vLayout);
    this->setCentralWidget(windowCentralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
