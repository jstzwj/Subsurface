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

#include "widget/scombobox.h"

#include "widget/namecolorwidget.h"
#include "widget/colorbox.h"
#include "widget/spushbutton.h"

class CreatePrimitiveTab : public QWidget
{
    Q_OBJECT
public:
    explicit CreatePrimitiveTab(QWidget *parent = nullptr);

protected:
    QVBoxLayout * mainLayout;
    SComboBox * primitiveType;
    QGroupBox * objectTypeGroup;
    QGroupBox * nameAndColorGroup;

    QGridLayout * standardPrimitivesLayout;
    QVBoxLayout * nameAndColorLayout;
    SPushButton * boxButton;
    SPushButton * coneButton;

    NameColorWidget *nameAndColor;

protected:
    void showStandardPrimitives();
signals:

public slots:
};

#endif // CREATEPRIMITIVETAB_H
