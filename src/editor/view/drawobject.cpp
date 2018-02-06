#include "drawobject.h"

namespace subsurface
{

    void draw_object(const objects::Scence &scence, const short dflag)
    {
        for(const std::weak_ptr<objects::SObject> &each : scence.objectsManager)
        {
            objects::DispList displist;
            each.lock()->getDispList(&displist);

        }
    }

    void drawDispListsolid(const std::list<objects::DispList> &displist, objects::SObject *obj, const short dflag, const objects::Color &wireColor, const bool useGLSL)
    {

    }

}
