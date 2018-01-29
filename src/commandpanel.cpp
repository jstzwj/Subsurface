#include "commandpanel.h"

CommandPanel::CommandPanel(QWidget *parent)
    :QWidget(parent)
{
    // tab widget
    tabWidget = new QTabWidget();
    // tabs
    objectTab = new QDialog();
    modificationTab = new QDialog();
    tabWidget->insertTab(0, objectTab, "Object");
    tabWidget->insertTab(0, modificationTab, "Modification");

    // layout
    mainLayout = new QVBoxLayout();
    mainLayout->setMargin(0);
    mainLayout->addWidget(tabWidget);

    this->setLayout(mainLayout);
}
