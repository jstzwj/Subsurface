#include "commandpanel.h"

CommandPanel::CommandPanel(QWidget *parent)
    :QWidget(parent)
{
    // tab widget
    tabWidget = new QTabWidget();
    // tabs
    createTab = new CreateTab();
    modifyTab = new ModifyTab();
    tabWidget->insertTab(0, createTab, "create");
    tabWidget->insertTab(1, modifyTab, "modify");

    // layout
    mainLayout = new QVBoxLayout();
    mainLayout->setMargin(0);
    mainLayout->addWidget(tabWidget);

    this->setLayout(mainLayout);
}
