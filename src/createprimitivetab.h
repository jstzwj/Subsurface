#ifndef CREATEPRIMITIVETAB_H
#define CREATEPRIMITIVETAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>

class CreatePrimitiveTab : public QWidget
{
    Q_OBJECT
public:
    explicit CreatePrimitiveTab(QWidget *parent = nullptr);

protected:
    QVBoxLayout * mainLayout;
    QComboBox * primitiveType;
signals:

public slots:
};

#endif // CREATEPRIMITIVETAB_H
