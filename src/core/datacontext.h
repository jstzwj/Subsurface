#ifndef DATACONTEXT_H
#define DATACONTEXT_H

#include"scence/scence.h"

namespace subsurface
{
    class DataContext
    {
    public:
        DataContext();
        scence::Scence scene;
    };
}

#endif // DATACONTEXT_H
