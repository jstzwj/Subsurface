#include "stoolbarbutton.h"

SToolBarButton::SToolBarButton(QWidget *parent) : QPushButton(parent)
{

}

SToolBarButton::SToolBarButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{

}
