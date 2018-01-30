#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include <QWidget>
#include <QTabWidget>
#include <QDialog>
#include <QVBoxLayout>

#include "createtab.h"
#include "modifytab.h"

class CommandPanel:public QWidget
{
    Q_OBJECT
public:
    CommandPanel(QWidget *parent = Q_NULLPTR);

protected:
    QTabWidget * tabWidget;
    CreateTab * createTab;
    ModifyTab * modifyTab;
    QVBoxLayout * mainLayout;
};

#endif // COMMANDPANEL_H
