#include "modifytab.h"

ModifyTab::ModifyTab(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    nameAndColor = new NameColorWidget(this);
    modifyList = new SComboBox(this);


    mainLayout->addWidget(nameAndColor);
    mainLayout->addWidget(modifyList);
    mainLayout->addStretch();
    this->setLayout(mainLayout);
}
