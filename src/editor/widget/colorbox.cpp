#include "colorbox.h"

ColorBox::ColorBox(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    colorButton = new QPushButton(this);

    mainLayout->addWidget(colorButton);
    this->setLayout(mainLayout);

    setColor(Qt::lightGray);

    connect(colorButton, SIGNAL(clicked()), this, SLOT(clickButton()));
}

void ColorBox::setColor(const QColor &color)
{
    QPalette palette;
    palette.setColor(QPalette::Button, color);
    selectedColor = color;
    colorButton->setPalette(palette);
    colorButton->setAutoFillBackground(true);
    colorButton->setFlat(true);

    // shadow
    QGraphicsDropShadowEffect *effert = new QGraphicsDropShadowEffect(colorButton);
    effert->setOffset(2,2);
    colorButton->setGraphicsEffect(effert);
}

void ColorBox::clickButton()
{
    QColor color = QColorDialog::getColor(selectedColor);

    if (color.isValid())
    {
        setColor(color);
    }
    else
    {
        qDebug() << color.redF() << color.greenF() << color.blueF();
    }
}
