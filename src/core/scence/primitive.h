#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "vector.h"
namespace subsurface
{
    namespace scence
    {
        class Primitive
        {
        public:
            Primitive();

        protected:
            Vector3f position;
        };
    }
}

#endif // PRIMITIVE_H
