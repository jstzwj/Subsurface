#ifndef SCENCE_H
#define SCENCE_H

#include <vector>
#include <memory>
#include <list>
#include"sobject.h"
#include "geometry.h"
#include "vector.h"
#include "point.h"

namespace subsurface
{
    namespace objects
    {
        class Scence
        {
        public:
            Scence();

        public:
            std::list<std::shared_ptr<SObject>> objectsManager;
        };
    }

}



#endif // SCENCE_H
