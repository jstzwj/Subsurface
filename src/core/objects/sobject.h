#ifndef SOBJECT_H
#define SOBJECT_H

#include <list>

#include"../data/id.h"
#include"../data/serialization/serializable.h"
#include"point.h"

namespace subsurface
{
    namespace data
    {
        class SObject : public Serializable
        {
        public:
            SObject();
            ID id;
            scence::Point3f dimensions;
            SObject *parent;
            std::list<SObject *> children;

        };
    }
}


#endif // SOBJECT_H
