#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <gl/GLU.h>
#include <gl/GL.h>

class ViewWidget : public QOpenGLWidget
{
public:
    ViewWidget(QWidget * parent = Q_NULLPTR);
    ~ViewWidget();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
};

#endif // VIEWWIDGET_H
