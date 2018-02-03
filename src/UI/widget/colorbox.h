#ifndef COLORBOX_H
#define COLORBOX_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QColor>
#include <QPalette>
#include <QPushButton>
#include <QColorDialog>
#include <QDebug>
#include <QGraphicsDropShadowEffect>

class ColorBox : public QWidget
{
    Q_OBJECT
public:
    explicit ColorBox(QWidget *parent = nullptr);

    void setColor(const QColor& color);

protected:
    QVBoxLayout *mainLayout;
    QPushButton *colorButton;
    QColor selectedColor;
signals:

public slots:
    void clickButton();
};

#endif // COLORBOX_H
