#ifndef SCENCE_H
#define SCENCE_H

#include <vector>
#include"sobject.h"
#include "geometry.h"
#include "vector.h"
#include "point.h"

namespace subsurface
{
    namespace scence
    {
        class Scence : public data::SObject
        {
        public:
            Scence();

        protected:

        private:
            std::vector<SObject> objectsList;
        };
    }

}



#endif // SCENCE_H
