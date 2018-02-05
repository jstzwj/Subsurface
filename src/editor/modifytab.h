#ifndef MODIFYTAB_H
#define MODIFYTAB_H

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QListWidget>

#include "widget/scombobox.h"
#include "widget/namecolorwidget.h"

class ModifyTab : public QWidget
{
    Q_OBJECT
public:
    explicit ModifyTab(QWidget *parent = nullptr);

protected:
    QVBoxLayout * mainLayout;
    NameColorWidget *nameAndColor;
    SComboBox *modifyList;
    QListWidget *modifierStack;
signals:

public slots:
};

#endif // MODIFYTAB_H
