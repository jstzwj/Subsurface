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
    QHBoxLayout * nameAndColorLayout;
    QPushButton * boxButton;
    QPushButton * coneButton;

    QLineEdit *nameLineEdit;
    ColorBox *colorBox;

protected:
    void setNameAndColor(const QString &name, const QColor &color);
    void showStandardPrimitives();
signals:

public slots:
};

#endif // CREATEPRIMITIVETAB_H
