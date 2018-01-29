#include "createtab.h"

CreateTab::CreateTab(QWidget *parent) : QDialog(parent)
{
    // layout
    mainLayout = new QVBoxLayout();
    mainLayout->setMargin(0);
    // tabwidget
    createTypeTabWidget = new QTabWidget();
    primitiveTab = new CreatePrimitiveTab();

    createTypeTabWidget->insertTab(0, primitiveTab, "primitive");
    mainLayout->addWidget(createTypeTabWidget);

    this->setLayout(mainLayout);
}
