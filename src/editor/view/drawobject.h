#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

#include <list>

#include <QOpenGLFunctions_3_2_Core>

#include "../../core/objects/displist.h"
#include "../../core/objects/sobject.h"
#include "../../core/objects/color.h"
#include "../../core/objects/scence.h"

namespace subsurface
{
    void draw_object(const objects::Scence &scence, const short dflag);

    void drawDispListsolid(const std::list<subsurface::objects::DispList>& displist,
                           subsurface::objects::SObject *obj,
                           const short dflag,
                           const subsurface::objects::Color & wireColor,
                           const bool useGLSL);
}


#endif // DRAWOBJECT_H
