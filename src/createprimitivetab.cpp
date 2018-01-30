#include "createprimitivetab.h"

CreatePrimitiveTab::CreatePrimitiveTab(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    primitiveType = new QComboBox(this);
    primitiveType->addItem("Stantard Primitives");

    mainLayout->addWidget(primitiveType);
    mainLayout->addStretch();

    this->setLayout(mainLayout);
}
