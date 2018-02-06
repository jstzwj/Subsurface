#include "displist.h"


namespace subsurface
{
    namespace objects
    {
        DispList::DispList()
        {
            OpenGLCore = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_2_Core>();
            idxNum = 0;
        }

        void DispList::initDispList(QOpenGLShaderProgram *program)
        {
            bool result = program->isLinked();
            if (!result)
                return;
            this->program = program;
            GLuint programID=program->programId();
            m_MLocationMat = OpenGLCore->glGetUniformLocation(programID, "M");
            m_VLocationMat = OpenGLCore->glGetUniformLocation(programID, "V");
            m_PLocationMat = OpenGLCore->glGetUniformLocation(programID, "P");
            m_PosVector = OpenGLCore->glGetAttribLocation(programID, "pos");
            m_ColorVector = OpenGLCore->glGetAttribLocation(programID, "color");
        }

        void DispList::createVBO(VertexInfo* data, int num)
        {
            bool result = program->isLinked();
            if (!result)
                return;
            idxNum = num;
            OpenGLCore->glGenBuffers(1, &vbo);
            OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            OpenGLCore->glBufferData(GL_ARRAY_BUFFER, sizeof(VertexInfo) * num, data, GL_DYNAMIC_DRAW);
            OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void DispList::createIBO(unsigned int *idx, int num)
        {
            bool result = program->isLinked();
            if (!result)
                return;
            idxNum = num;
            OpenGLCore->glGenBuffers(1, &ibo);
            OpenGLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
            OpenGLCore->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*num, idx, GL_DYNAMIC_DRAW);
            OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void DispList::drawDispList(const QMatrix4x4& projectionMatrix)
        {
            bool result = program->isLinked();
            if (!result)
                return;
            QMatrix4x4 nMormalMat;
            OpenGLCore->glUniformMatrix4fv(m_MLocationMat, 1, GL_FALSE, nMormalMat.data());
            OpenGLCore->glUniformMatrix4fv(m_VLocationMat, 1, GL_FALSE, nMormalMat.data());
            OpenGLCore->glUniformMatrix4fv(m_PLocationMat, 1, GL_FALSE, projectionMatrix.data());

            OpenGLCore->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            // 使用DrawArrays绘制
            OpenGLCore->glEnableVertexAttribArray(m_PosVector);
            OpenGLCore->glVertexAttribPointer(m_PosVector, 3, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)0);
            OpenGLCore->glEnableVertexAttribArray(m_ColorVector);
            OpenGLCore->glVertexAttribPointer(m_ColorVector, 4, GL_FLOAT, GL_FALSE, sizeof(VertexInfo), (void*)(sizeof(float) * 3));

            // 使用DrawElement绘制
            OpenGLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
            OpenGLCore->glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
            OpenGLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    }
}
