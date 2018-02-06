#ifndef SCONTEXT_H
#define SCONTEXT_H

#include "datacontext.h"
#include "editorcontext.h"


namespace subsurface
{
    class SContext
    {
    public:
        SContext();
        DataContext dataContext;
        EditorContext editorContext;
    };
}


#endif // SCONTEXT_H
