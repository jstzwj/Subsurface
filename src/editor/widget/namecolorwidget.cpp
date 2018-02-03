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

void NameColorWidget::setNameAndColor(const QString &name, const QColor &color)
{
    nameLineEdit->setText(name);
    colorBox->setColor(color);
}
