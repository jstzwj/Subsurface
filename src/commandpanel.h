#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include <QWidget>
#include <QTabWidget>
#include <QDialog>
#include <QVBoxLayout>

class CommandPanel:public QWidget
{
    Q_OBJECT
public:
    CommandPanel(QWidget *parent = Q_NULLPTR);

protected:
    QTabWidget * tabWidget;
    QDialog * objectTab;
    QDialog * modificationTab;
    QVBoxLayout * mainLayout;
};

#endif // COMMANDPANEL_H
