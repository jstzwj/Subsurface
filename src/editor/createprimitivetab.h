#ifndef CREATEPRIMITIVETAB_H
#define CREATEPRIMITIVETAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QGroupBox>
#include <QPushButton>
#include <QColor>
#include <QLineEdit>

#include "widget/namecolorwidget.h"
#include "widget/colorbox.h"

class CreatePrimitiveTab : public QWidget
{
    Q_OBJECT
public:
    explicit CreatePrimitiveTab(QWidget *parent = nullptr);

protected:
    QVBoxLayout * mainLayout;
    QComboBox * primitiveType;
    QGroupBox * objectTypeGroup;
    QGroupBox * nameAndColorGroup;

    QGridLayout * standardPrimitivesLayout;
    QVBoxLayout * nameAndColorLayout;
    QPushButton * boxButton;
    QPushButton * coneButton;

    NameColorWidget *nameAndColor;

protected:
    void showStandardPrimitives();
signals:

public slots:
};

#endif // CREATEPRIMITIVETAB_H
