#ifndef CUSTOMEDTITLEBAR_H
#define CUSTOMEDTITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QApplication>

class CustomedTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit CustomedTitleBar(QWidget *parent = Q_NULLPTR);
    ~CustomedTitleBar();

protected:

    // double click titlebar and maximize it
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    // drag and move the window
    virtual void mousePressEvent(QMouseEvent *event);

    // set title and icon
    virtual bool eventFilter(QObject *obj, QEvent *event);

private slots:

    // minimize, maximize and close operation
    void onClicked();

private:

    // maximize
    void updateMaximize();

private:
    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;
};

#endif // CUSTOMEDTITLEBAR_H
