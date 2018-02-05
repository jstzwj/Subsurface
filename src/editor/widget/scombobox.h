#ifndef SCOMBOBOX_H
#define SCOMBOBOX_H

#include <QWidget>
#include <QComboBox>

class SComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit SComboBox(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SCOMBOBOX_H
