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
    // 获取Uniform ID & Attribute ID
    m_MLocationMat = OpenGLCore->glGetUniformLocation(programId, "M");
    m_VLocationMat = OpenGLCore->glGetUniformLocation(programId, "V");
    m_PLocationMat = OpenGLCore->glGetUniformLocation(programId, "P");
    m_PosVector = OpenGLCore->glGetAttribLocation(programId, "pos");
    m_ColorVector = OpenGLCore->glGetAttribLocation(programId, "color");
    // 创建VBO
    VertexInfo nVertexInfo[3];
    nVertexInfo[0].pos[0] = 0.0f;
    nVertexInfo[0].pos[1] = 0.0f;
    nVertexInfo[0].pos[2] = -30.0f;
    nVertexInfo[0].color[0] = 1.0f;
    nVertexInfo[0].color[1] = 0.0f;
    nVertexInfo[0].color[2] = 0.0f;
    nVertexInfo[0].color[3] = 1.0f;
    nVertexInfo[1].pos[0] = 10.0f;
    nVertexInfo[1].pos[1] = 0.0f;
    nVertexInfo[1].pos[2] = -30.0f;
    nVertexInfo[1].color[0] = 0.0f;
    nVertexInfo[1].color[1] = 1.0f;
    nVertexInfo[1].color[2] = 0.0f;
    nVertexInfo[1].color[3] = 1.0f;
    nVertexInfo[2].pos[0] = 0.0f;
    nVertexInfo[2].pos[1] = 10.0f;
    nVertexInfo[2].pos[2] = -30.0f;
    nVertexInfo[2].color[0] = 0.0f;
    nVertexInfo[2].color[1] = 0.0f;
    nVertexInfo[2].color[2] = 1.0f;
    nVertexInfo[2].color[3] = 1.0f;
    // 创建VBO
    OpenGLCore->glGenBuffers(1, &m_VBO);
    OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    OpenGLCore->glBufferData(GL_ARRAY_BUFFER, sizeof(VertexInfo) * 3, nVertexInfo, GL_STATIC_DRAW);
    OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, 0);
    // 创建IBO
    unsigned int index[3] = {0, 1, 2};
    OpenGLCore->glGenBuffers(1, &m_IBO);
    OpenGLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    OpenGLCore->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
    OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, 0);
    glClearColor(41.0f / 255.0f, 71.0f / 255.0f, 121.0f / 255.0f, 1.0f);
}

void ViewWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    bool result = m_Program->bind();
    if (!result)
        return;
    QMatrix4x4 nMormalMat;
    OpenGLCore->glUniformMatrix4fv(m_MLocationMat, 1, GL_FALSE, nMormalMat.data());
    OpenGLCore->glUniformMatrix4fv(m_VLocationMat, 1, GL_FALSE, nMormalMat.data());
    OpenGLCore->glUniformMatrix4fv(m_PLocationMat, 1, GL_FALSE, mProjectionMatrix.data());
    OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // 使用DrawArrays绘制
    OpenGLCore->glEnableVertexAttribArray(m_PosVector);
    OpenGLCore->glVertexAttribPointer(m_PosVector, 3, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)0);
    OpenGLCore->glEnableVertexAttribArray(m_ColorVector);
    OpenGLCore->glVertexAttribPointer(m_ColorVector, 4, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)(sizeof(float) * 3));
    OpenGLCore->glDrawArrays(GL_TRIANGLES, 0, 3);
    OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, 0);
    // 使用DeawElement绘制
    // OpenGLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    // OpenGLCore->glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    // OpenGLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
