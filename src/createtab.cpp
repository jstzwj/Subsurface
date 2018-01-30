#include "createtab.h"

CreateTab::CreateTab(QWidget *parent) : QDialog(parent)
{
    // layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    // tabwidget
    createTypeTabWidget = new QTabWidget(this);
    primitiveTab = new CreatePrimitiveTab(this);

    createTypeTabWidget->insertTab(0, primitiveTab, "primitive");
    mainLayout->addWidget(createTypeTabWidget);

    this->setLayout(mainLayout);
}
