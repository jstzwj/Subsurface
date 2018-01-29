#ifndef CREATETAB_H
#define CREATETAB_H

#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QVBoxLayout>

#include "createprimitivetab.h"

class CreateTab : public QDialog
{
    Q_OBJECT
public:
    explicit CreateTab(QWidget *parent = nullptr);

protected:
    QVBoxLayout * mainLayout;
    QTabWidget * createTypeTabWidget;
    CreatePrimitiveTab * primitiveTab;

signals:

public slots:
};

#endif // CREATETAB_H
