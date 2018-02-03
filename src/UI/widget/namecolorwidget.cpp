#include "namecolorwidget.h"

NameColorWidget::NameColorWidget(QWidget *parent) : QWidget(parent)
{
    // name and color
    nameLineEdit = new QLineEdit("", this);
    colorBox = new ColorBox(this);

    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(nameLineEdit);
    mainLayout->addWidget(colorBox);

    this->setLayout(mainLayout);
}
