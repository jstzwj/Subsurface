#ifndef STOOLBARBUTTON_H
#define STOOLBARBUTTON_H

#include <QPushButton>
#include <QWidget>

class SToolBarButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SToolBarButton(QWidget *parent = Q_NULLPTR);
    explicit SToolBarButton(const QString &text, QWidget *parent = Q_NULLPTR);

signals:

public slots:
};

#endif // STOOLBARBUTTON_H
