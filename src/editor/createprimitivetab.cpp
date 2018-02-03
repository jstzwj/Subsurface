#include "createprimitivetab.h"

CreatePrimitiveTab::CreatePrimitiveTab(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    primitiveType = new QComboBox(this);
    primitiveType->addItem("Stantard Primitives");

    // groupbox
    objectTypeGroup = new QGroupBox(this);
    nameAndColorGroup = new QGroupBox(this);

    // layouts
    standardPrimitivesLayout= new QGridLayout(objectTypeGroup);
    nameAndColorLayout = new QVBoxLayout(nameAndColorGroup);

    // objects
    boxButton = new SPushButton(tr("Box"), objectTypeGroup);
    boxButton->setCheckable(true);
    boxButton->setAutoExclusive(true);

    coneButton = new SPushButton(tr("Cone"), objectTypeGroup);
    coneButton->setCheckable(true);
    coneButton->setAutoExclusive(true);

    // name and color
    nameAndColor = new NameColorWidget(nameAndColorGroup);

    standardPrimitivesLayout -> addWidget(boxButton, 0, 0);
    standardPrimitivesLayout -> addWidget(coneButton, 0, 1);

    nameAndColorLayout->addWidget(nameAndColor);

    objectTypeGroup->setTitle("Object Type");
    nameAndColorGroup->setTitle("Name and Color");

    mainLayout->addWidget(primitiveType);
    mainLayout->addWidget(objectTypeGroup);
    mainLayout->addWidget(nameAndColorGroup);
    mainLayout->addStretch();

    this->setLayout(mainLayout);

    showStandardPrimitives();
}


void CreatePrimitiveTab::showStandardPrimitives()
{
    objectTypeGroup->setLayout(standardPrimitivesLayout);
}
