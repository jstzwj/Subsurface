#ifndef PLANE_H
#define PLANE_H

#include "normal.h"
namespace subsurface
{
    namespace objects
    {
        class Plane
        {
        public:
            Plane();
            Normal3f normal;
            Float dist;
        };
    }
}

#endif // PLANE_H
