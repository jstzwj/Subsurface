#ifndef DISPLIST_H
#define DISPLIST_H

#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLShaderProgram>

namespace subsurface
{
    namespace objects
    {

        struct VertexInfo
        {
            float pos[3];
            float color[4];
        };

        class DispList
        {
        public:
            DispList();

            void initDispList(QOpenGLShaderProgram *program);
            void createVBO(VertexInfo *data, int num);
            void createIBO(unsigned int *idx, int num);
            void drawDispList(const QMatrix4x4 &projectionMatrix);

        protected:
            QOpenGLFunctions_3_2_Core *OpenGLCore;

            QOpenGLShaderProgram *program;

            GLint m_MLocationMat;
            GLint m_VLocationMat;
            GLint m_PLocationMat;
            GLint m_PosVector;
            GLint m_ColorVector;

            GLuint vbo;
            GLuint ibo;
            int idxNum;
        };
    }
}


#endif // DISPLIST_H
