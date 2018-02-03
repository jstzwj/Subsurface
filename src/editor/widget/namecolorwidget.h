#ifndef NAMECOLORWIDGET_H
#define NAMECOLORWIDGET_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QColor>
#include <QWidget>

#include "colorbox.h"

class NameColorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NameColorWidget(QWidget *parent = nullptr);

    void setNameAndColor(const QString &name, const QColor &color);

protected:
    QHBoxLayout * mainLayout;
    QLineEdit *nameLineEdit;
    ColorBox *colorBox;
signals:

public slots:
};

#endif // NAMECOLORWIDGET_H
