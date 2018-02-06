#ifndef SOBJECT_H
#define SOBJECT_H

#include <list>
#include <memory>

#include"../data/id.h"
#include"../data/serialization/serializable.h"
#include "point.h"
#include "color.h"
#include "aabbboundbox.h"
#include "displist.h"

namespace subsurface
{
    namespace objects
    {
        class SObject : public data::Serializable
        {
        public:
            SObject();
            data::ID id;
            Color color;
            AABBBoundBox bb;
            Point3f pivot;

            std::weak_ptr<SObject> parent;
            std::list<std::weak_ptr<SObject>> children;

            DispList displist;

        public:
            void getDispList(const DispList *list)const
            {
                list = &displist;
            }
        };
    }
}


#endif // SOBJECT_H
