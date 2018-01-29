#include "createprimitivetab.h"

CreatePrimitiveTab::CreatePrimitiveTab(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout();
    primitiveType = new QComboBox();
    primitiveType->addItem("Stantard Primitives");

    mainLayout->addWidget(primitiveType);
    mainLayout->addStretch();

    this->setLayout(mainLayout);
}
