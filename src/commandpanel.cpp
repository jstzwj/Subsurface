#include "commandpanel.h"

CommandPanel::CommandPanel(QWidget *parent)
    :QWidget(parent)
{
    // tab widget
    tabWidget = new QTabWidget(this);
    // tabs
    createTab = new CreateTab(this);
    modifyTab = new ModifyTab(this);
    tabWidget->insertTab(0, createTab, "create");
    tabWidget->insertTab(1, modifyTab, "modify");

    // layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(tabWidget);

    this->setLayout(mainLayout);
}
