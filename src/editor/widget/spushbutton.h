#ifndef SPUSHBUTTON_H
#define SPUSHBUTTON_H

#include <QPushButton>
#include <QWidget>

class SPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SPushButton(QWidget *parent = Q_NULLPTR);
    explicit SPushButton(const QString &text, QWidget *parent = Q_NULLPTR);

signals:

public slots:
};

#endif // SPUSHBUTTON_H
