#include "createtab.h"

CreateTab::CreateTab(QWidget *parent) : QDialog(parent)
{
    // layout
    mainLayout = new QVBoxLayout(this);
    // mainLayout->setMargin(1);
    // tabwidget
    createTypeGroup = new QButtonGroup(this);
    createTypeGroupBox = new QWidget(this);
    createTypeLayout = new QHBoxLayout(createTypeGroupBox);
    geometryButton = new SToolBarButton(createTypeGroupBox);
    shapesButton = new SToolBarButton(createTypeGroupBox);
    lightsButton = new SToolBarButton(createTypeGroupBox);
    camerasButton = new SToolBarButton(createTypeGroupBox);
    primitiveTab = new CreatePrimitiveTab(this);

    geometryButton->setFixedWidth(20);
    shapesButton->setFixedWidth(20);
    lightsButton->setFixedWidth(20);
    camerasButton->setFixedWidth(20);

    geometryButton->setCheckable(true);
    shapesButton->setCheckable(true);
    lightsButton->setCheckable(true);
    camerasButton->setCheckable(true);
    geometryButton->setChecked(true);

    createTypeLayout->addWidget(geometryButton);
    createTypeLayout->addWidget(shapesButton);
    createTypeLayout->addWidget(lightsButton);
    createTypeLayout->addWidget(camerasButton);
    createTypeLayout->addStretch();

    createTypeGroup->addButton(geometryButton);
    createTypeGroup->addButton(shapesButton);
    createTypeGroup->addButton(lightsButton);
    createTypeGroup->addButton(camerasButton);

    createTypeGroup->setExclusive(true);

    createTypeGroupBox->setLayout(createTypeLayout);

    mainLayout->addWidget(createTypeGroupBox);
    mainLayout->addWidget(primitiveTab);

    this->setLayout(mainLayout);
}
