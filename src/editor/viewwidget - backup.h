#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions_3_2_Core>
#include <QTimer>
#include <gl/GLU.h>
#include <gl/GL.h>

struct VertexInfo
{
    float pos[3];
    float color[4];
};

class ViewWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    ViewWidget(QWidget * parent = Q_NULLPTR);
    ~ViewWidget();

protected:
    // 创建一个GPU程序
    GLuint createGPUProgram(QString nVertexShaderFile, QString nFragmentShaderFile);
    QOpenGLShader *m_VertexShader;
    QOpenGLShader *m_FragmentShader;
    QOpenGLShaderProgram *m_Program;
    // MVP Location
    GLint m_MLocationMat;
    GLint m_VLocationMat;
    GLint m_PLocationMat;
    GLint m_PosVector;
    GLint m_ColorVector;
    // VBO
    GLuint m_VBO;
    // IBO
    GLuint m_IBO;
    QMatrix4x4 mProjectionMatrix;
    QOpenGLFunctions_3_2_Core *OpenGLCore = nullptr;

    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void printContextInformation();
};

#endif // VIEWWIDGET_H
