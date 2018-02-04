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
    stackedWidget = new QStackedWidget(this);

    QIcon geometryButtonIcon(":rsc/images/Geometry.png");
    geometryButton->setIcon(geometryButtonIcon);
    QIcon shapesButtonIcon(":rsc/images/Shapes.png");
    shapesButton->setIcon(shapesButtonIcon);
    QIcon lightsButtonIcon(":rsc/images/Lights.png");
    lightsButton->setIcon(lightsButtonIcon);
    QIcon camerasButtonIcon(":rsc/images/Cameras.png");
    camerasButton->setIcon(camerasButtonIcon);

    geometryButton->setFixedWidth(32);
    shapesButton->setFixedWidth(32);
    lightsButton->setFixedWidth(32);
    camerasButton->setFixedWidth(32);

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

    stackedWidget->addWidget(primitiveTab);

    mainLayout->addWidget(createTypeGroupBox);
    mainLayout->addWidget(stackedWidget);

    this->setLayout(mainLayout);
}
