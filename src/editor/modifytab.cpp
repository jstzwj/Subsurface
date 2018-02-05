#include "modifytab.h"

ModifyTab::ModifyTab(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    nameAndColor = new NameColorWidget(this);
    modifyList = new SComboBox(this);
    modifierStack = new QListWidget(this);
    modifierStack->setObjectName("modifierStack");

    mainLayout->addWidget(nameAndColor);
    mainLayout->addWidget(modifyList);
    mainLayout->addWidget(modifierStack);
    mainLayout->addStretch();
    this->setLayout(mainLayout);
}
