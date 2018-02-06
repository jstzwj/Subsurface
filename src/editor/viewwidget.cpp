#include "viewwidget.h"


ViewWidget::ViewWidget(QWidget * parent)
    :QOpenGLWidget(parent)
{
    this->setCursor(Qt::CrossCursor);
}

ViewWidget::~ViewWidget()
{
}

GLuint ViewWidget::createGPUProgram(QString nVertexShaderFile, QString nFragmentShaderFile)
{
    m_VertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
    bool isOK = m_VertexShader->compileSourceFile(nVertexShaderFile);
    if (!isOK)
    {
        delete m_VertexShader;
        m_VertexShader = nullptr;
        return 0;
    }
    m_FragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
    if (!m_FragmentShader->compileSourceFile(nFragmentShaderFile))
    {
        delete m_VertexShader;
        delete m_FragmentShader;
        m_FragmentShader = nullptr;
        return 0;
    }
    m_Program = new QOpenGLShaderProgram(this);
    m_Program->addShader(m_VertexShader);
    m_Program->addShader(m_FragmentShader);
    m_Program->link();
    return m_Program->programId();
}

void ViewWidget::initializeGL()
{
    createGPUProgram(":/shaders/vertexshader.vert", ":/shaders/fragmentshader.frag");
    OpenGLCore = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_2_Core>();
    GLuint programId = m_Program->programId();

    scontext = &subsurface::Singleton<subsurface::SContext>::getInstance();
    subsurface::objects::Scence scence = scontext->dataContext.scene;

    for(const std::weak_ptr<subsurface::objects::SObject> &each : scence.objectsManager)
    {
        subsurface::objects::DispList displist;
        each.lock()->getDispList(&displist);
        displist.initDispList(m_Program);
    }

    glClearColor(41.0f / 255.0f, 71.0f / 255.0f, 121.0f / 255.0f, 1.0f);
}

void ViewWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    bool result = m_Program->bind();
    if (!result)
        return;

    subsurface::objects::Scence scence = scontext->dataContext.scene;

    for(const std::weak_ptr<subsurface::objects::SObject> &each : scence.objectsManager)
    {
        subsurface::objects::DispList displist;
        each.lock()->getDispList(&displist);
        displist.drawDispList(mProjectionMatrix);
    }

    m_Program->release();
}

void ViewWidget :: resizeGL(int w,int h)
{
    mProjectionMatrix.setToIdentity();
    mProjectionMatrix.perspective(45.0f, w * 1.0f / h, 0.1f, 500.0f);
}

// 打印相关信息，调试用
void ViewWidget::printContextInformation()
{
    QString glType;
    QString glVersion;
    QString glProfile;

    // 获取版本信息
    glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

    // 获取 Profile 信息
#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
    switch (format().profile())
    {
        CASE(NoProfile);
        CASE(CoreProfile);
        CASE(CompatibilityProfile);
    }
#undef CASE

    qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";
}
