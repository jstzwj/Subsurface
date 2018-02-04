#ifndef CREATETAB_H
#define CREATETAB_H

#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QButtonGroup>

#include "widget/stoolbarbutton.h"
#include "createprimitivetab.h"

class CreateTab : public QDialog
{
    Q_OBJECT
public:
    explicit CreateTab(QWidget *parent = nullptr);

protected:
    QVBoxLayout * mainLayout;
    // createTypeTabWidget;
    QButtonGroup * createTypeGroup;
    QWidget * createTypeGroupBox;
    QHBoxLayout * createTypeLayout;
    SToolBarButton * geometryButton;
    SToolBarButton * shapesButton;
    SToolBarButton * lightsButton;
    SToolBarButton * camerasButton;
    CreatePrimitiveTab * primitiveTab;


signals:

public slots:
};

#endif // CREATETAB_H
