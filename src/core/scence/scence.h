#ifndef SCENCE_H
#define SCENCE_H

#include <vector>
#include "primitive.h"

namespace subsurface
{
    namespace scence
    {
        class Scence
        {
        public:
            Scence();

        private:
            std::vector<Primitive> primitiveList;
        };
    }

}



#endif // SCENCE_H
